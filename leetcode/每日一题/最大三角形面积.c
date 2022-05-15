double Area(double a ,double b, double c)
{
    if(a+b<c||abs(a-b)>c)
    return (double)0;
    double p= (a+b+c)/2;    //ÇØ¾ÅÉØ¹«Ê½
    double pro=p*(p-a)*(p-b)*(p-c);
    return sqrt(pro);
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){

    double ret=0;
    for(int i=0;i<pointsSize;i++)
    {
        for(int j=0;j<pointsSize;j++)
        {
            for(int k=0;k<pointsSize;k++)
            {
                double a , b , c;
                double area=0;
                a=sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
                b=sqrt(pow(points[i][0]-points[k][0],2)+pow(points[i][1]-points[k][1],2));
                c=sqrt(pow(points[j][0]-points[k][0],2)+pow(points[j][1]-points[k][1],2));
                area=Area(a,b,c);
                ret=area>ret?area:ret;
            }
        }
    }
    return ret;
}


