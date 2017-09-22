class BinTreeNode
{
private:
	int data;
	BinTreeNode *left,*right;
public:
	BinTreeNode(const int &item,BinTreeNode *lPtr = NULL,BinTreeNode *rPtr = NULL):data(item),left(lPtr),right(rPtr){};
	void set_data(int item)
	{
		data = item;
	}
	int get_data()const
	{
		return data;
	}
	void set_left(BinTreeNode *l)
	{
		left = l;
	}
	BinTreeNode* get_left()const
	{
		return left;
	}
	void set_right(BinTreeNode *r)
	{
		right = r;
	}
	BinTreeNode* get_right()const
	{
		return right;
	}
};