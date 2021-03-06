/**
 * p37 随机测试数据生成程序
 * @author 张校
 * @date 2021-10-25
 * @brief 使用方法：直接编译运行
 */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include<time.h>
class TheTree {
public:
    struct Node {
        static const char *CharList;
        static const int MAX_NODES_NUM = 100000;
        static const int NODES_NUM_MOD = 52;
        char c;
        Node *l, *r;
        Node(const char c_, Node *l_ = NULL, Node *r_ = NULL) : c(c_), l(l_), r(r_) {}
        ~Node() {Clear();}
        void Clear() { if( l ) delete l; if( r ) delete r; }
        Node *InsertChild(const char c_, const bool left_child) { if( left_child ) return l = new Node(c_); return r = new Node(c_); }
        
        /**
         * void PrintString(std::ostream &out)
         * @brief 打印作为输入的字符串
         */
        void PrintString(std::ostream &out)
        {
            out << c;
            if( l ) l->PrintString(out);
            else out << '#';
            if( r ) r->PrintString(out);
            else out << '#';
        }
        /**
         * void ShowByLayer(std::ostream &out, int layer)
         * @brief 逐行输出结果
         * @param int layer 当前节点行数
         */
        void ShowByLayer(std::ostream &out, int layer)
        {
            if( r ) r->ShowByLayer(out, layer + 1);
            for( int i = 0; i < layer; i ++ )
                out << "     ";
            out << c << std::endl;
            if( l ) l->ShowByLayer(out, layer + 1);
        }
        /**
         * void PrintByMode(std::ostream &out, const int mode)
         * @brief 按模式打印
         * @param int mode 模式（1：前序；2：中序；3：后续）
         */
        void PrintByMode(std::ostream &out, const int mode)
        {
            if( mode == 1 ) out << c;
            if( l ) l->PrintByMode(out, mode);
            if( mode == 2 ) out << c;
            if( r ) r->PrintByMode(out, mode);
            if( mode == 3 ) out << c;
        }
        /**
         * void GenarateNode(const int n)
         * @brief 生成树的节点
         * @param int n 当前子树所有孩子包含的节点个数（不包括自己）
         */
        void GenarateNode(const int n)
        {
            if( n > 0 )
            {
                if( n == 1 || rand() % 100 < 10 )
                {
                    if( rand() % 2 == 0 )
                    {
                        l = new Node(Node::CharList[rand() % NODES_NUM_MOD]);
                        l->GenarateNode(n - 1);
                    }
                    else
                    {
                        r = new Node(CharList[rand() % NODES_NUM_MOD]);
                        r->GenarateNode(n - 1);
                    }
                }
                else
                {
                    int left_children = rand() % (n - 1);
                    l = new Node(CharList[rand() % NODES_NUM_MOD]);
                    l->GenarateNode(left_children);
                    r = new Node(CharList[rand() % NODES_NUM_MOD]);
                    r->GenarateNode(n - left_children - 2);
                }
            }
        }
    };

    TheTree() { root = NULL; }
    ~TheTree() { Clear(); }
    void Clear() { if( root ) delete root; root = NULL; }

    /**
     * @brief 按模式打印
     */
    void PrintByMode(std::ostream &out, const int mode) { root->PrintByMode(out , mode); out << std::endl; }
    /**
     * @brief 层序遍历
     */
    void PrintByLayer(std::ostream &out)
    {
        std::queue<Node *> Q;
        Q.push(root);
        while( ! Q.empty() )
        {
            Node *pointer = Q.front();
            if( pointer != NULL )
            {
                out << pointer->c;
               
                Q.push(pointer->l);
                Q.push(pointer->r);
            }
            Q.pop();
        }
        out << std::endl;
    }
    /**
     * @brief 逐行打印
     */
    void ShowByLayer(std::ostream &out) { root->ShowByLayer(out, 0); }
    void PrintString(std::ostream &out) { root->PrintString(out); out << std::endl; }
    void GenarateTree(int n)
    {
        Clear();
        root = new Node(Node::CharList[rand() % Node::NODES_NUM_MOD]);
        root->GenarateNode(n - 1);
    }
private:
    Node *root;
};

const char * TheTree::Node::CharList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    srand((unsigned)time(NULL));
    int test_num = 10;
    for( int i = 1; i <= test_num; i ++ )
    {
        std::string inputfile = "input" + std::to_string(i) + ".txt";
        std::string outputfile = "output" + std::to_string(i) + ".txt";
        std::ofstream fin(inputfile.c_str());
        std::ofstream fout(outputfile.c_str());

        int nodes;
        if( i <= test_num * 0.2 )
            nodes = 10;
        else if( i <= test_num * 0.4 )
            nodes = 100;
        else
            nodes = TheTree::Node::MAX_NODES_NUM;
        
        TheTree *tree = new TheTree();

        tree->GenarateTree(nodes);
        tree->PrintString(fin);
        tree->PrintByMode(fout, 1);
        tree->PrintByMode(fout, 2);
        tree->PrintByMode(fout, 3);
        tree->PrintByLayer(fout);
        tree->ShowByLayer(fout);
        delete tree;
    }
    
}
