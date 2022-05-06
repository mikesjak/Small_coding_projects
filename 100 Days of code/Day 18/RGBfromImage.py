import colorgram

rgb_colors = []
colors = colorgram.extract("image.jpeg", 1000)
for color in colors:
    r = color.rgb.r
    g = color.rgb.r
    b = color.rgb.r
    new_color = (r, g, b)
    rgb_colors.append(new_color)

print(rgb_colors)

