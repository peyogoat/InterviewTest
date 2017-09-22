class BinTree
{
private:
	BinTreeNode *root;
public:
	BinTree(BinTreeNode *t = NULL):root(t){};
	~BinTree(){delete root;};
	void set_root(BinTreeNode *t)
	{
		root = t;
	}
	BinTreeNode* get_root()const
	{
		return root;
	}
	//create
	BinTreeNode* create_tree();
	//PreOrder
	void pre_order(BinTreeNode *r)const;
	//midOrder
	void in_order(BinTreeNode* r)const;
	//postOrder
	void post_order(BinTreeNode* r)const;
	//levelOrder
	void level_order(BinTreeNode* r)const;
	int get_leaf_num(BinTreeNode* r)const;
	int get_tree_height(BinTreeNode* r)const;
	void swap_left_right(BinTreeNode* r);
	void find_route(BinTreeNode* r)const;
	BinTreeNode* get_nearest_common_father(BinTreeNode* r,BinTreeNode* pNode1,BinTreeNode* pNode2)const;
//print route with sum = sum
	void print_rout(BinTreeNode* r,int sum)const;
	bool is_in_tree(BinTreeNode* r,BinTreeNode* t)const;
};