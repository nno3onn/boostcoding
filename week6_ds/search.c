// 숫자 50이 트리에 있으면 true, 아니면 false 반환

bool search(node *tree){
    if (if tree == NULL){
        return false;
    }else if (50 < tree->number){
        return search(tree->left);
    }else if (50 > tree->number){
        return search(tree->right);
    }else{
        return true;
    }
}