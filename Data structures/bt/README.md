# Simple Binary tree 

### Sumary

- This is a showcase how you can create a Binary tree in C
- I will only show how to created and delete a Node in a tree
- Other functions like searching in tree is a bit difficult for begginers, but I want to do it later

### Explanation

##### So how can we imagine Binary tree?
- I will show you our binary tree in a few pictures

1. Before inserting 8
```md
        2
       / \
      9   3
     /   / \
    7   1   0
```

2. Afret inserting 8
```md
         2
       /   \
      9     3
     / \   / \
    7   8  1  0
```
3. After deleting 7
```md
         2
       /   \
      9     3
       \   / \
        8  1  0
```
- If you wanted to insert 2 more Nodes it would look like this
```md
         2
       /   \
      9     3
     / \   / \
    6   8  1  0
   /
  0   
```
- It would simply fill the tree from left to right from the highest avaliable place