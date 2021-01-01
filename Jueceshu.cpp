// Jueceshu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ID3.h"
 
using namespace std;
 
enum outlook {SUNNY, OVERCAST, RAIN };//用枚举定义了四种属性
enum temp    {HOT,   MILD,     COOL };
enum hum     {HIGH,  NORMAL         };
enum windy   {WEAK,  STRONG         };

//样本数据
int samples[14][4] =
{
    {SUNNY   ,       HOT ,      HIGH  ,       WEAK  },
    {SUNNY   ,       HOT ,      HIGH  ,       STRONG},
    {OVERCAST,       HOT ,      HIGH  ,       WEAK  },
    {RAIN    ,       MILD,      HIGH  ,       WEAK  },
    {RAIN    ,       COOL,      NORMAL,       WEAK  },
    {RAIN    ,       COOL,      NORMAL,       STRONG},
    {OVERCAST,       COOL,      NORMAL,       STRONG},
    {SUNNY   ,       MILD,      HIGH  ,       WEAK  },
    {SUNNY   ,       COOL,      NORMAL,       WEAK  },
    {RAIN    ,       MILD,      NORMAL,       WEAK  },
    {SUNNY   ,       MILD,      NORMAL,       STRONG},
    {OVERCAST,       MILD,      HIGH  ,       STRONG},
    {OVERCAST,       HOT ,      NORMAL,       WEAK  },
    {RAIN    ,       MILD,      HIGH  ,       STRONG}
};

//测试数据
int samples2[6][4] =
{
    {SUNNY   ,       HOT ,      NORMAL,       WEAK  },
    {SUNNY   ,       HOT ,      NORMAL,       STRONG},
    {RAIN    ,       HOT ,      NORMAL,       WEAK  },
    {SUNNY   ,       MILD,      NORMAL,       WEAK  },
    {SUNNY   ,       COOL,      HIGH  ,       STRONG},
    {SUNNY   ,       COOL,      HIGH  ,       WEAK  }
};

int main()
{
    ID3 Tree(4);        //初始化有四个属性
    Tree.PushData((int *)&samples[0], 0);
    Tree.PushData((int *)&samples[1], 0);
    Tree.PushData((int *)&samples[2], 1);
    Tree.PushData((int *)&samples[3], 1);
    Tree.PushData((int *)&samples[4], 1);
    Tree.PushData((int *)&samples[5], 0);
    Tree.PushData((int *)&samples[6], 1);
    Tree.PushData((int *)&samples[7], 0);
    Tree.PushData((int *)&samples[8], 1);
    Tree.PushData((int *)&samples[9], 1);
    Tree.PushData((int *)&samples[10], 1);
    Tree.PushData((int *)&samples[11], 1);
    Tree.PushData((int *)&samples[12], 1);
    Tree.PushData((int *)&samples[13], 0);           //将样本数据Push给二维链表
 
    Tree.Build();       //构建决策树
    for(int i = 0; i < 6; ++i)
        cout << "predict value :    " <<Tree.Match( (int *)&samples2[i] ) << endl;         //根据新的样本预测结果
    return 0;
}