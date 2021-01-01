// ID3.h: interface for the ID3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ID3_H__8521F2B6_33CD_416A_81C1_8A2B799CB722__INCLUDED_)
#define AFX_ID3_H__8521F2B6_33CD_416A_81C1_8A2B799CB722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _ID3_H_
#define _ID3_H_
 
#pragma warning(disable : 4786)
#include <utility>
#include <list>
#include <map>
 
#define Type int   //样本数据类型
 
#define   Map1        std::map< int, Type >    //定义一维map
#define   Map2        std::map< int, Map1 >    //定义二维map
#define   Map3        std::map< int, Map2 >    //定义三维map
#define   Pair        std::pair<int, Type>
#define   List        std::list< Pair >        //一维list
#define   SampleSpace std::list< List >        //二维list 用于存放样本数据
#define   Child       std::map< int, Node* >   //定义后继节点集合
#define   CI          const_iterator
 
/*
 *   在ID3算法中，用二维链表存放样本，结构为list< list< pair<int, int> > >，简记为SampleSpace，取名样本空间
 *   样本数据从根节点开始往下遍历。每一个节点的定义如下结构体
 */
 
struct Node
{
    int index;                    //当前节点样本最大增益对应第index个属性，根据这个进行分类的
    int type;                     //当前节点的类型
    Child next;                   //当前节点的后继节点集合
    SampleSpace sample;           //未分类的样本集合
};
 
class ID3{
 
public:
 
    ID3(int );    
    ~ID3();
 
    void PushData(const Type*, const Type);   //将样本数据Push给二维链表
    void Build();                             //构建决策树
    int  Match(const Type*);                  //根据新的样本预测结果
    void Print();                             //打印决策树的节点的值
 
private:
 
    void   _clear(Node*);
    void   _build(Node*, int);
    int    _match(const int*, Node*);
    void   _work(Node*);
    double _entropy(const Map1&, double);
    int    _get_max_gain(const SampleSpace&);
    void   _split(Node*, int);
    void   _get_data(const SampleSpace&, Map1&, Map2&, Map3&);
    double _info_gain(Map1&, Map2&, double, double);
    int    _same_class(const SampleSpace&);
    void   _print(Node*);
 
private:
 
    int dimension;
    Node *root;
};
 
#endif // _ID3_H_

#endif // !defined(AFX_ID3_H__8521F2B6_33CD_416A_81C1_8A2B799CB722__INCLUDED_)
