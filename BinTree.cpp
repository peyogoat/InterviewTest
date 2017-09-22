#include "BinTree.h"
//先序遍历
BinTreeNode* BinTree::create_tree()
{
	int item;
	BinTreeNode *t,*t_l,*t_r;
	cin>>item;
	if(item!='#')
	{
		BinTreeNode *pTmpNode = new BinTreeNode(item);
		t = pTmpNode;
		t_l = create_tree();
		t->set_left(t_l);
		t_r = create_tree();
		t->set_right(t_r);
		return t;
	}
	else
	{
		t = NULL;
		return t;
	}
}
void BinTree::pre_order(BinTreeNode *r) const
{
	BinTreeNode *pTmpNode = r;
	if(pTmpNode != NULL)
	{
		cout<<pTmpNode->get_data()<<" ";
		pre_order(pTmpNode->get_left());
		pre_order(pTmpNode->get_right());
	}
}

void BinTree::level_order(BinTreeNode *r)const
{
	if(r = NULL)
	{
		return;
	}
	deque<BinTreeNode*> q;
	q.push_back(r);
	while(!q.empty())
	{
		BinTreeNode *pTmpNode = q.front()
		cout<<pTmpNode->get_data()<<" ";
		q.pop_front();
		if(pTmpNode->get_left()!=NULL)
		{
			q.push_back(pTmpNode->get_left());
		}
		if(pTmpNode->get_right()!=NULL)
		{
			q.push_back(pTmpNode->get_right());
		}

	}
}

int BinTree::get_leaf_num(BinTreeNode* r)const
{
	if(r == NULL)
	{
		return 0;
	}
	if(r->get_left()==NULL && r->get_right()==NULL)
	{
		return 1;
	}
	return get_leaf_num(r->get_left()) + get_leaf_num(r->get_right());
}

int BinTree::get_tree_height(BinTreeNode *r)const
{
	if(r == NULL)
	{
		return 0;
	}
	if(r->get_left()==NULL && r->get_right()==NULL)
	{
		return 1;
	}
	int l_height = get_tree_height(r->get_left());
	int r_height = get_tree_height(r->get_right());
	return l_height>r_height? l_height+1:r_height+1;
}

void BinTree::swap_left_right(BinTreeNode *r)
{
	if(r == NULL)
	{
		return;
	}
	BinTreeNode *pTmpNode = r->get_left();
	r->set_left(r->get_right());
	r->set_right(pTmpNode);
	swap_left_right(r->get_left());
	swap_left_right(r->get_right());
}

bool BinTree::is_in_tree(BinTreeNode *r,BinTreeNode *t)const
{
	if(r == NULL)
	{
		return false;
	}
	else if(r == t)
	{
		return true;
	}
	else
	{
		bool has = false;
		if(r->get_left()!=NULL)
		{
			has = is_in_tree(r->get_left(),t);
		}
		if(r->get_right()!=NULL)
		{
			has = is_in_tree(r->get_right(),t);
		}
		return has;
	}
}

deque<BinTreeNode *>rout_q1;
queue<BinTreeNode *>rout_q2;
bool BinTree::find_route(BinTreeNode* r,BinTreeNode *pNode,bool which)const
{
	static bool sym = 0;
	BinTreeNode *pTmpNode = r;
	if(sym)
	{
		if(pTmpNode == this->get_root())
		{
			sym = 0;
		}
		return 0;
	}
	if(pTmpNode == NULL || pNode == NULL)
	{
		return;
	}
	if(which)
	{
		rout_q1.push_back(r);
	}
	else
	{
		rout_q2.push_back(r);
	}
	if(pTmpNode == pNode)
	{
		sym = 1;
		return 0;
	}
	find_route(pTmpNode->get_left(),pNode,which);
	find_route(pTmpNode->get_right(),pNode,which);
	if(which)
	{
		rout_q1.pop_back(r);
	}
	else
	{
		rout_q2.pop_back(r);
	}
}

BinTreeNode* BinTree::get_nearest_common_father(BinTreeNode *r,BinTreeNode *pNode1,BinTreeNode *pNode2)const
{
	if(r == NULL|| pNode1 == NULL ||pNode2 == NULL)
	{
		return NULL;
	}
	BinTreeNode *pTmpNode = NULL;
	bool rst_Node1 = find_route(r,pNode1,1);
	bool rst_Node2 = find_route(r,pNode2,0);
	if(rst_Node1 && rst_Node2)
	{
		while(rout_q1.front()==rout_q2.front())
		{
			pTmpNode = rout_q2.front();
			rout_q2.pop_front();
			rout_q1.pop_front();
		}
		return pTmpNode;
	}
	else
	{
		return NULL;
	}
	
}

stack<BinTreeNode *>dfs_s;
stack<BinTreeNode *>print_s;
void BinTree::print_rout(BinTreeNode *r,int sum)const
{
	if(r == NULL)
	{
		return;
	}
	sum -=r->get_data();
	dfs_s.push(r);
	if(sum <= 0)
	{
		if(sum == 0)
		{
			while(!dfs_s.empty())
			{
				print_s.push(dfs_s.top());
				dfs_s.pop();
			}
			while(!print_s.empty())
			{
				cout<<print_s.top()->get_data()<<' ';
				dfs_s.push(print_s.top);
				print_s.pop();
			}
			cout<<endl;
		}
		dfs_s.pop();
		return;
	}
	print_rout(r->get_left(),sum);
	print_rout(r->get_right(),sum);
	sum += r->get_data();
	dfs_s.pop();
}