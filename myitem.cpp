#include "myitem.h"
#include <QtGlobal>
#include <time.h>
unsigned char item1[16]=
{
    1,1,1,0,
    1,0,1,0,
    1,1,1,0,
    0,0,1,0
};
unsigned char item2[16]=
{
    0,0,0,0,
    1,1,1,0,
    0,1,0,0,
    0,1,0,0
};
unsigned char item3[16]=
{
    0,0,0,0,
    1,0,1,0,
    1,1,1,0,
    0,0,1,0
};
unsigned char item4[16]=
{
    0,0,1,1,
    0,0,0,1,
    0,0,1,1,
    0,0,0,1
};
unsigned char item5[16]=
{
    0,0,0,0,
    0,0,1,0,
    0,0,0,0,
    0,0,0,0
};
unsigned char item6[16]=
{
    0,0,0,0,
    0,0,0,0,
    0,1,1,0,
    0,0,0,0
};
unsigned char item7[16]=
{
    1,0,1,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0
};
unsigned char item8[16]=
{
    0,0,0,0,
    0,1,1,0,
    0,1,0,0,
    0,0,0,0
};
unsigned char item9[16]=
{
    0,0,1,0,
    0,0,1,0,
    0,0,1,0,
    0,0,1,0
};

MyItem::MyItem()
{
    qsrand(time(0));
}
MyItem::~Myitem()
{
}
unsigned char* MyItem::getItem()
{
    unsigned char* currentItem=NULL;
    switch(qrand()%9)
    {
        case 0:currentItem=item1;break;
        case 1:currentItem=item2;break;
        case 2:currentItem=item3;break;
        case 3:currentItem=item4;break;
        case 4:currentItem=item5;break;
        case 5:currentItem=item6;break;
        case 6:currentItem=item7;break;
        case 7:currentItem=item8;break;
        case 8:currentItem=item9;break;
    }
    return currentItem;
}
int MyItem::currentItem_endPos(unsigned char *currentItem, unsigned char end)
{
    int k=0;
    switch(end)
    {
    case 'd':
    {
        for(int row=3;row>=0;row--)
        {
            for(int col=0;col<4;col++)
            {
                if(*(currentItem+row*4+col) || k==1)
                    return row;
            }
        }
    }
    case 'r':
    {
        for(int col=3;col>=0;col--)
        {
            for(int row=0;row<4;row++)
            {
                if(*(currentItem+row*4+col) || k==1)
                    return col;
            }
        }
    }
    case 'l':
    {
        for(int col=3;col>=0;col--)
        {
            for(int row=0;row<4;row++)
            {
                if(*(currentItem+row*4+col) || k==1)
                    return col;
            }
        }
    }
    default:
        return 0;
    }
}
unsigned char* MyItem::itemChange(unsigned char *currentItem)
{
    unsigned char* tmp=new unsigned char[16];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            *(tmp+(3-j)*4+i)=*(currentItem+i*4+j); //rotate 90 du !
        }
    }
    return tmp;
}
