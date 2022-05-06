#include <iostream>
#include <cstdio>

struct BMP_header {
    char name[2];
    unsigned int size;
    int garbage;
    unsigned int image_offset;
};

struct DIB_header {
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned short int color_planes;
    unsigned short int bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int tmp[4];
};

struct RGB {
    unsigned char blue;
    unsigned char red;
    unsigned char green;
};

struct Image {
    int height;
    int width;
    struct RGB **rgb;
};


Image readImage(FILE *fp, int height, int width){
    struct Image pic;
    pic.rgb = (struct RGB**) malloc(height* sizeof( void* ) );
    pic.height = height;
    pic.width = width;
    int bytesToRead = ((24 * width + 31)/32)*4;
    int numOfRGB = bytesToRead/sizeof(RGB) + 1;
    for ( int i = height-1; i >= 0; i-- ) {
        pic.rgb[i] = (RGB*) malloc(numOfRGB*sizeof( RGB ) + 10);
        fread( pic.rgb[i], 1, bytesToRead, fp );
    }

    return pic;
}

void freeImage ( Image pic ) {
    for ( int i = pic.height - 1; i >= 0; i--) free(pic.rgb[i]);
    free(pic.rgb);
}

unsigned char grayscale(RGB rgb) {
    return ((0.3 * rgb.red) + (0.6 * rgb.green) + (0.1 * rgb.blue));
}

void toGrayscale(Image pic) {
    for ( int i = 0; i < pic.height; i++ ){
        for ( int j=0; j < pic.width; j++ )
            pic.rgb[i][j].red = pic.rgb[i][j].green = pic.rgb[i][j].blue = grayscale(pic.rgb[i][j]);
    }
}

int crateBWImage( BMP_header header, DIB_header dibheader, Image pic ) {
    FILE *fpw = fopen("new.bmp","w");
    if (fpw == nullptr) return 0;

    toGrayscale(pic);

    fwrite(header.name,2,1,fpw);
    fwrite(&header.size, 3*sizeof(int), 1, fpw);
    fwrite(&dibheader, sizeof(DIB_header), 1, fpw);

    for ( int i = pic.height-1; i >= 0; i-- ) {
        fwrite( pic.rgb[i], ((24 * pic.width + 31)/32)*4, 1, fpw );
    }
    fclose(fpw);
    return 1;
}


void imageToASCII(Image img) {
    unsigned char gs;
    char textpixel[] = {'@', '#', '%', 'O', 'a', '-', '.', ' '};
    for ( int i = 0; i < img.height; i++){
        for ( int j = 0; j < img.width; j++) {
            gs = grayscale(img.rgb[i][j]);
            std::cout << (textpixel[7-gs/32]);
        }
        std::cout << std::endl;
    }
}

int openFile(char *filename) {
    FILE *fp = fopen(filename,"rb");
    if (fp == nullptr) return 1;

    BMP_header header;
    DIB_header dibheader;

    fread(header.name, 2, 1, fp);
    fread(&header.size, 3* sizeof(int), 1, fp);
    std::cout << "First two characters: " << header.name[0] <<header.name[1] << std::endl;
    //if ((header.name[0] != 'B') && (header.name[1] != 'M')) {fclose(fp); return 1; }

    std::cout << "Size: " << header.size << std::endl;
    std::cout << "Offset: " << header.image_offset << std::endl;

    fread(&dibheader, sizeof(dibheader), 1, fp);
    //if ((dibheader.header_size != 40) || (dibheader.compression != 0) || dibheader.bits_per_pixel != 24) {fclose(fp); return 1; }

    std::cout << "Header size: " << dibheader.header_size << std::endl;
    std::cout << "Width: " << dibheader.width << std::endl;
    std::cout << "Height: " << dibheader.height << std::endl;
    std::cout << "Color planes: " << dibheader.color_planes << std::endl;
    std::cout << "Bits per pixel: " << dibheader.bits_per_pixel << std::endl;
    std::cout << "Compression: " << dibheader.compression << std::endl;
    std::cout << "Image size: " << dibheader.image_size << std::endl;

    fseek(fp, header.image_offset, SEEK_SET);
    Image image = readImage(fp, dibheader.height, dibheader.width);
    imageToASCII(image);
    crateBWImage(header, dibheader, image);
    fclose(fp);
    freeImage(image);
    return 1;
}


int main(int argc, char* argv[]) {
    openFile(argv[1]);
    return 0;
}
