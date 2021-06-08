
//Distance Vector Routing Algorithm

#include<stdio.h>
#include<string.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);//Enter intra and inter distance of nodes in terms of cost matrix
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];//Initialise the distance equal to cost matrix
            rt[i].from[j]=j;
        }
    }
printf("Cost matrix before update\n");
for(i=0;i<nodes;i++)
        {
            
            for(j=0;j<nodes;j++)
            {
                printf("\t %d  ",costmat[i][j]);
            }
     printf("\n");
        }
    printf("\n\n");


printf("Updation Process\n");

        do
        {
            count=0;
            for(i=0;i<nodes;i++)//Arbitary vertex k and calculating the direct distance from the node i to k using the cost matrix
            for(j=0;j<nodes;j++)//Add the distance from k to node j
            for(k=0;k<nodes;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])//Calculating the minimum distance
                {
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d Distance %d ",j+1,rt[i].from[j]+1,rt[i].dist[j]);
            }
        }
    printf("\n\n");

printf("Cost matrix After update\n");
for(i=0;i<nodes;i++)
        {
            
            for(j=0;j<nodes;j++)
            {
                printf("\t %d  ",rt[i].dist[j]);
            }
     printf("\n");
        }
    printf("\n\n");

}
