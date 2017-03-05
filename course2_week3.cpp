#include<bits/stdc++.h>
using namespace std;
struct atnode
{
    int data;
    int height;
    int countt;
    struct atnode*left;
    struct atnode*right;
};
int aheight(struct atnode* root)
{
    if(root==NULL)
        return 0;
    else
        return (root->height);
}
struct atnode*rightrotate(struct atnode* root)
{
    struct atnode* x=root->left;
    struct atnode* y=x->right;

    x->right=root;
    root->left=y;

    root->height=max(aheight(root->left),aheight(root->right))+1;
    x->height=max(aheight(x->left),aheight(x->right))+1;

    return x;
}
struct atnode*leftrotate(struct atnode* root)
{
    struct atnode* x=root->right;
    struct atnode* y=x->left;

    x->left=root;
    root->right=y;

    root->height=max(aheight(root->left),aheight(root->right))+1;
    x->height=max(aheight(x->left),aheight(x->right))+1;

    return x;
}
struct atnode*insertt(struct atnode*root,int d)
{
    if(!root)
    {
        root=(struct atnode *)malloc(sizeof(struct atnode));
        root->data=d;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else
    {
        if(d==root->data)
        {
            root->countt++;
        }
        if(d<root->data)
        {
            root->left=insertt(root->left,d);
        }
        else
        {
            root->right=insertt(root->right,d);
        }
        root->height=max(aheight(root->left),aheight(root->right))+1;
        int a=aheight(root->left)-aheight(root->right);
        if((a>1)&&(d<root->left->data))
           return rightrotate(root);
        if((a<-1)&&(d>root->right->data))
            return leftrotate(root);
        if((a>1)&&(d>root->left->data))
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if((a<-1)&&(d<root->right->data))
        {
            root->right=rightrotate(root->right);
            return leftrotate(root->left);
        }
        return root;
    }
}
void preorder(struct atnode* root)
{
    if(root){
    cout<<root->data<<" "<<root->height<<endl;
    preorder(root->left);
    preorder(root->right);
    }
}
struct atnode*minvalue(struct atnode *root)
{
    while(root->left)
        root=root->left;
    return root;
}
struct atnode*deletenode(struct atnode *root,int d)
{
    if(d>root->data)
        root->right=deletenode(root->right,d);
    if(d<root->data)
        root->left=deletenode(root->left,d);
    else
    {
        if(root->countt>1)
        {
            root->countt--;
            return root;
        }
        if((root->left==NULL)||(root->right==NULL))
        {
            struct atnode*temp=root->left?root->left:root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
                *root=*temp;
            free(temp);
        }
        else
        {
            struct atnode*temp=minvalue(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,d);
        }
    }
    if(root==NULL)
        return root;

     root->height=max(aheight(root->left),aheight(root->right))+1;
        int a=aheight(root->left)-aheight(root->right);
        if((a>1)&&(d<root->left->data))
            rightrotate(root);
        if((a<-1)&&(d>root->right->data))
            leftrotate(root);
        if((a>1)&&(d>root->left->data))
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if((a<-1)&&(d<root->right->data))
        {
            root->right=rightrotate(root->right);
            return leftrotate(root->left);
        }
        return root;
}
int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct atnode *root = NULL;
    int a,med_sum=0;
  /* Constructing tree given in the above figure */
  for  (int i=0;i<10000;i++)
  {
      cin>>a;
      root=insertt(root,a);
      med_sum+=root->data;
  }
  cout<<med_sum<<endl;
}
