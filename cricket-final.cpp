#include<stdio.h>
#include<graphics.h>
int over_limit,speed=1,difficulties,pcrun,pcwicket,toss_win,play,pctosswin=0;
char messageap[15];
void Autoplay();
void mainscreen()
{
    char over_match,t[25];
    int toss;
    int i, maxx, maxy,radius;
    maxx=getmaxx();
    maxy=getmaxy();
x:
    setcolor(10);
    outtextxy(100,40,"PRESS....... ");
    outtextxy(100,70,"1....1 OVER MATCH ");
    outtextxy(100,100,"2....3 OVER MATCH ");
    outtextxy(100,130,"3....5 OVER MATCH ");
    setcolor(15);
    int bat1[10]= {495,110,527,110,470,250,438,250,495,110};
    int handle1[10]= {330+200,60,340+200,60,335+180,110,325+180,110,330+200,60};
    setfillstyle(1,12);
    fillpoly(5,bat1);
    setfillstyle(1,14);
    fillpoly(5,handle1);
    setcolor(15);
    circle(490,250,10);
    setfillstyle(1,4);
    floodfill(490,250,15);
    setcolor(15);
    over_match=getch();
    cleardevice();
    if(over_match==49)
        over_limit=1;
    if(over_match==50)
        over_limit=3;
    if(over_match==51)
        over_limit=5;
    if(over_match!=49&&over_match!=50&&over_match!=51)
        goto x;
    cleardevice();
    //3rd window
y:
    setcolor(11);
    outtextxy(100,40,"PRESS....... ");
    outtextxy(100,70,"E....EASY ");
    outtextxy(100,100,"M....MEDIUM ");
    outtextxy(100,130,"D....DIFFICULT ");
    setcolor(15);
    setcolor(1);
    line(390,330,390,450);
    line(400,330,400,450);
    circle(395,330,5);
    line(390,450,395,460);
    line(400,450,395,460);
    line(425,330,425,450);
    line(435,330,435,450);
    circle(430,330,5);
    line(425,450,430,460);
    line(435,450,430,460);
    line(460,330,460,450);
    line(470,330,470,450);
    circle(465,330,5);
    line(460,450,465,460);
    line(470,450,465,460);
    rectangle(392,320,428,325);
    rectangle(430,300,468,305);
    setcolor(4);
    for(radius=0; radius<=15; radius++)
        circle(447,345,radius);
    setcolor(15);
    difficulties=getch();
    if(difficulties==69||difficulties==101)
        speed=1;
    if(difficulties==77||difficulties==109)
        speed=2;
    if(difficulties==68||difficulties==100)
        speed=5;
    if(difficulties!=69&&difficulties!=77&&difficulties!=68&&difficulties!=101&&difficulties!=109&&difficulties!=100)
        goto y;
    cleardevice();
    //4th window
    setcolor(14);
    outtextxy(100,50,"PRESS UP ARROW KEY :");
    setcolor(2);
    outtextxy(100,70,"TO START THE BALL");
    setcolor(14);
    outtextxy(100,100,"PRESS LEFT ARROW KEY :");
    setcolor(2);
    outtextxy(100,120,"TO MOVE THE BAT LEFT FROM CURRENT POSITION");
    setcolor(14);
    outtextxy(100,150,"PRESS RIGHT ARROW KEY :");
    setcolor(2);
    outtextxy(100,170,"TO MOVE THE BAT RIGHT FROM CURRENT POSITION");
    setcolor(4);
    outtextxy(100,250,"press any key to continue....");
    setcolor(15);
    getch();
    cleardevice();
    //5th window
    setcolor(14);
    outtextxy(270,200,"LOADING....");
    setcolor(2);
    for(i=0; i<=400; i++)
    {
        rectangle(110+i,250,510,275);
        delay(15);
    }
    cleardevice();
    //last window
m:
    setcolor(9);
    outtextxy(50,50,"SELECT YOUR OPTION FOR TOSS");
    setcolor(14);
    outtextxy(50,75,"PRESS....");
    setcolor(2);
    outtextxy(50,100,"H TO (HEAD)");
    outtextxy(50,125,"T TO (TAIL)");
    toss=getch();
    if(toss!=72&&toss!=104&&toss!=84&&toss!=116)
        goto m;
    cleardevice();
    if(pctosswin%4==1)
    {
        setcolor(2);
        outtextxy(50,70,"PC HAS WON THE TOSS");
        setcolor(14);
        outtextxy(50,100,"AND SELECTED TO BAT FIRST");
        setcolor(7);
        outtextxy(200,250,"press any key to continue....");
        getch();
        cleardevice();
        Autoplay();
        setcolor(12);
        outtextxy(100,80,"FIRST INNIGS END");
        sprintf(messageap, "PC SCORE : %d/%d",pcrun,pcwicket);
        setcolor(14);
        outtextxy(100,120,messageap);
        setcolor(11);
        sprintf(t,"YOUR TARGET IS MORE THAN %d",pcrun);
        outtextxy(100,160,t);
        setcolor(7);
        outtextxy(200,250,"press any key to continue for  second innings....");
        //getch();
        getch();
        cleardevice();
    }
    if(pctosswin%4==3)
    {
        setcolor(2);
        outtextxy(50,70,"PC HAS WON THE TOSS");
        setcolor(14);
        outtextxy(50,100,"AND SELECTED TO BALL FIRST");
        setcolor(7);
        outtextxy(200,250,"press any key to continue....");
        //getch();
        getch();
        cleardevice();
    }
n:
    if(pctosswin%4==0||pctosswin%4==2)
    {
        setcolor(2);
        outtextxy(50,70,"YOU HAVE WON THE TOSS");
        setcolor(14);
        outtextxy(50,100,"WHAT WILL YOU TAKE FIRST");
        setcolor(11);
        outtextxy(50,125,"PRESS....");
        setcolor(4);
        outtextxy(50,150,"1 TO BAT");
        outtextxy(50,175,"2 TO BALL");
        toss_win=getch();
        cleardevice();
        if(toss_win==50)
        {
            Autoplay();
            setcolor(12);
            outtextxy(100,80,"FIRST INNIGS END");
            sprintf(messageap, "PC SCORE : %d/%d",pcrun,pcwicket);
            setcolor(14);
            outtextxy(100,120,messageap);
            setcolor(11);
            sprintf(t,"YOUR TARGET IS MORE THAN %d",pcrun);
            outtextxy(100,160,t);
            setcolor(7);
            outtextxy(200,250,"press any key to continue for  second innings....");
            //getch();
            getch();
            cleardevice();
        }
        if(toss_win!=49&&toss_win!=50)
            goto n;
    }
}
void Autoplay()
{
    cleardevice();
    if(over_limit==1&&(difficulties==69||difficulties==101))
    {
        pcrun=12;
        pcwicket=2;
    }
    else if(over_limit==3&&(difficulties==69||difficulties==101))
    {
        pcrun=36;
        pcwicket=3;
    }
    else if(over_limit==5&&(difficulties==69||difficulties==101))
    {
        pcrun=60;
        pcwicket=6;
    }
    else if(over_limit==1&&(difficulties==77||difficulties==109))
    {
        pcrun=16;
        pcwicket=1;
    }
    else if(over_limit==3&&(difficulties==77||difficulties==109))
    {
        pcrun=40;
        pcwicket=3;
    }
    else if(over_limit==5&&(difficulties==77||difficulties==109))
    {
        pcrun=64;
        pcwicket=3;
    }
    else if(over_limit==1&&(difficulties==68||difficulties==100))
    {
        pcrun=14;
        pcwicket=1;
    }
    else if(over_limit==3&&(difficulties==68||difficulties==100))
    {
        pcrun=38;
        pcwicket=3;
    }
    else if(over_limit==5&&(difficulties==68||difficulties==100))
    {
        pcrun=66;
        pcwicket=4;
    }
    int maxx,maxy,midx,midy;
    maxx=getmaxx();
    maxy=getmaxy();
    midx=maxx/2;
    midy=maxy/2;
    //bat
    setcolor(15);
    //pitch color
    setfillstyle(1,2);
    floodfill(1,1,15);
    circle(midx,midy,300);
    //pitch
    rectangle(midx-100,10,midx+100,400);
    setfillstyle(1,6);
    floodfill(midx-50,200,15);
    //wicket
    setfillstyle(1,7);
    bar(midx-20,20,midx-10,70);
    bar(midx-5,20,midx+5,70);
    bar(midx+10,20,midx+20,70);
    bar(midx-20,340,midx-10,390);
    bar(midx-5,340,midx+5,390);
    bar(midx+10,340,midx+20,390);
    //baller
    setfillstyle(1,9);
    circle(midx-30,420,20);
    floodfill(midx-30,420,15);
    setfillstyle(1,14);
    rectangle(midx-50,440,midx-10,470);
    floodfill(midx-40,450,15);
    //batsman1
    setfillstyle(1,4);
    circle(midx+50,30,20);
    floodfill(midx+50,30,15);
    setfillstyle(1,2);
    rectangle(midx+30,50,midx+70,80);
    floodfill(midx+31,51,15);
    //batsman2
    setfillstyle(1,4);
    circle(midx+50,340,20);
    floodfill(midx+50,340,15);
    setfillstyle(1,2);
    rectangle(midx+30,360,midx+70,390);
    floodfill(midx+31,361,15);
    int ia=40,ja;
    ja=ia/15;
    int bat[10]= {320+10,80,340+10,80,340+10-ia,140,320+10-ia,140,320+10,80};
    int handle[10]= {337+10,50,343+10,50,333+10-ja,80,327+10-ja,80,337+10,50};
    setcolor(0);
    setfillstyle(1,11);
    fillpoly(5,bat);
    setfillstyle(1,12);
    fillpoly(5,handle);
    setcolor(7);
    outtextxy(50,70,"AUTOPLAYING......");
    setcolor(4);
    for(int i=0; i<=400; i++)
    {
        rectangle(110+i,260,510,275);
        delay(15);
    }
    cleardevice();
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\BGI");
    int maxx,maxy,midx,midy;
    maxx=getmaxx();
    maxy=getmaxy();
    midx=maxx/2;
    midy=maxy/2;
    setcolor(2);
    for(int ii=0; ii<=10; ii++)
    {
        rectangle(ii,ii,maxx-ii,maxy-ii);
    }
    setcolor(2);
    for( int ii=0; ii<=130; ii++)
    {
        circle(maxx/2,maxy/2,ii);
        delay(10) ;
    }
    setcolor(5) ;
    outtextxy(210,40,"WELCOME TO A CRICKET");
    outtextxy(210,55,"press any key to continue....");
    getch();
    cleardevice();
start:
    int flag=0,counter=0,up=1,angle=0;
    int bat[10],handle[10];
    int i=40,j=0,k=0,a=0,r=0,o,t,run=0,wicket=0,over=0,overdetect=0;
    char ch,message[10],message1[10],message2[10],message3[10];
xx:
    setcolor(12);
    outtextxy(100,40,"PRESS....... ");
    outtextxy(100,70,"1 PLAY");
    outtextxy(100,100,"2 EXIT");
    play=getch();
    cleardevice();
    if(play==49)
    {

    }
    if(play==50)
    {
        goto ex;
    }
    if(play!=49&&play!=50)
        goto xx;
    //2nd window
    mainscreen();
    setbkcolor(2);
    while(1)                                   //infinite loop
    {
        //boundary
        circle(midx,midy,300);
        //pitch
        rectangle(midx-100,10,midx+100,400);
        setfillstyle(1,6);
        floodfill(midx-50,200,15);
        //wicket
        setfillstyle(1,7);
        bar(midx-20,20,midx-10,70);
        bar(midx-5,20,midx+5,70);
        bar(midx+10,20,midx+20,70);
        bar(midx-20,340,midx-10,390);
        bar(midx-5,340,midx+5,390);
        bar(midx+10,340,midx+20,390);
        //baller
        setfillstyle(1,9);
        circle(midx-30,420,20);
        floodfill(midx-30,420,15);
        setfillstyle(1,14);
        rectangle(midx-50,440,midx-10,470);
        floodfill(midx-40,450,15);
        //batsman1
        setfillstyle(1,4);
        circle(midx+50,30,20);
        floodfill(midx+50,30,15);
        setfillstyle(1,2);
        rectangle(midx+30,50,midx+70,80);
        floodfill(midx+31,51,15);
        //batsman2
        setfillstyle(1,4);
        circle(midx+50,340,20);
        floodfill(midx+50,340,15);
        setfillstyle(1,2);
        rectangle(midx+30,360,midx+70,390);
        floodfill(midx+31,361,15);
        //bat
        j=i/15;
        int bat[10]= {320+10,80,340+10,80,340+10-i,140,320+10-i,140,320+10,80};
        int handle[10]= {337+10,50,343+10,50,333+10-j,80,327+10-j,80,337+10,50};
        setcolor(0);
        setfillstyle(1,11);
        fillpoly(5,bat);
        setfillstyle(1,12);
        fillpoly(5,handle);
        setcolor(15);
        //ball
        if(flag==1)
        {
            if(up==1)
            {
                setcolor(8);
                setfillstyle(1,15);
                circle(midx-30+a,380-k,10);
                floodfill(midx-30+a,380-k,8);
                setcolor(15);
            }
            if(up==0)
            {
                setcolor(8);
                setfillstyle(1,15);
                circle(midx-30+a+angle,140+r,10);
                floodfill(midx-30+a+angle,140+r,8);
                setcolor(15);
            }
        }
        //checking bat hit ball
        int ballx=midx-30+a;
        int bally=380-k;
        if(bally==140&&ballx>325-i&&ballx<355-i)
        {
            up=0;

        }
        if(up==0)
        {
            if(difficulties==69||difficulties==101)
            {
                if(counter%7==0)
                {
                    r=r+1;
                    angle=angle+1;
                }
                if(counter%7==1)
                {
                    r=r+1;
                    angle=angle-1;
                }
                if(counter%7==2)
                {
                    r=r+2;
                    angle=angle+4;
                }
                if(counter%7==3)
                {
                    r=r+4;
                    angle=angle-1;
                }
                if(counter%7==4)
                {
                    r=r+1;
                    angle=angle-4;
                }
                if(counter%7==5)
                {
                    r=r+1;
                    angle=angle+2;
                }
                if(counter%7==6)
                {
                    r=r+2;
                    angle=angle-1;
                }
            }

            if(difficulties==77||difficulties==109)
            {
                if(counter%7==0)
                {
                    r=r+2;
                    angle=angle+2;
                }
                if(counter%7==1)
                {
                    r=r+2;
                    angle=angle-2;
                }
                if(counter%7==2)
                {
                    r=r+3;
                    angle=angle+5;
                }
                if(counter%7==3)
                {
                    r=r+5;
                    angle=angle-2;
                }
                if(counter%7==4)
                {
                    r=r+2;
                    angle=angle-5;
                }
                if(counter%7==5)
                {
                    r=r+2;
                    angle=angle+4;
                }
                if(counter%7==6)
                {
                    r=r+3;
                    angle=angle-2;
                }
            }
            if(difficulties==68||difficulties==100)
            {
                if(counter%7==0)
                {
                    r=r+3;
                    angle=angle+3;
                }
                if(counter%7==1)
                {
                    r=r+3;
                    angle=angle-3;
                }
                if(counter%7==2)
                {
                    r=r+4;
                    angle=angle+6;
                }
                if(counter%7==3)
                {
                    r=r+6;
                    angle=angle-3;
                }
                if(counter%7==4)
                {
                    r=r+3;
                    angle=angle-6;
                }
                if(counter%7==5)
                {
                    r=r+3;
                    angle=angle+5;
                }
                if(counter%7==6)
                {
                    r=r+4;
                    angle=angle-3;
                }
            }
            if(r>350&&(angle>350||angle<350))
            {
                if(counter%7==0)
                {
                    outtextxy(midx-270,midy+10,"SIX");
                    run=run+6;
                }
                if(counter%7==1)
                {
                    outtextxy(midx-270,midy+10,"FOUR");
                    run=run+4;
                }
                if(counter%7==2)
                {
                    outtextxy(midx-270,midy+10,"SIX");
                    run=run+6;
                }
                if(counter%7==3)
                {
                    outtextxy(midx-270,midy+10,"FOUR");
                    run=run+4;
                }
                if(counter%7==4)
                {
                    outtextxy(midx-270,midy+10,"SIX");
                    run=run+6;
                }
                if(counter%7==5)
                {
                    outtextxy(midx-270,midy+10,"SIX");
                    run=run+6;
                }
                if(counter%7==6)
                {
                    outtextxy(midx-270,midy+10,"SIX");
                    run=run+6;
                }
                getch();
                r=0;
                angle=0;
                up=1;
                k=400;
            }
        }
        //checking ball hit wicket
        if(bally==40&&ballx>midx-30&&ballx<midx+30)
        {
            wicket++;
            if(wicket==10)
            {
                outtextxy(midx+120,midy+50,"END THIS INNINGS");
                getch();
                goto z;
            }
            k=400;
            setcolor(0);
            setfillstyle(1,3);
            rectangle(midx-15,25,midx+15,40);
            floodfill(midx,30,0);
            setcolor(15);
            outtextxy(midx+160,midy+10,"OUT");
            getch();
        }

        if(kbhit())                         //check if a key is pressed
        {
            ch=getch();
            if(ch==72)
                flag=1;
            if(ch==75&&i<60)                    //move left
                i=i+10;
            if(ch==77&&i>20)                    //move right
                i=i-10;
        }
        if(flag==1&&up==1)
            k=k+speed;
        if(k>=400)
        {
            overdetect++;
            if(overdetect==6)
            {
                over++;
                if(over==over_limit)
                {
                    outtextxy(midx+120,midy+50,"END THIS INNINGS");
                    getch();
                    goto z;
                }
                overdetect=0;
            }
            flag=0;
            k=0;
            counter++;
            a=0;
            if(counter%7==0)
                a=a+10;
            if(counter%7==1)
                a=a-10;
            if(counter%7==2)
                a=a+20;
            if(counter%7==3)
                a=a-5;
            if(counter%7==4)
                a=a-20;
            if(counter%7==5)
                a=a+25;
            if(counter%7==6)
                a=a-7;
        }
        setcolor(15);
        sprintf(message2, "OVER : %d",over);
        outtextxy(midx+15,midy+180,message2);
        sprintf(message, "SCORE : %d",run);
        setcolor(1);
        outtextxy(midx-295,midy+200,message);
        sprintf(message1, "WICKET : %d",wicket);
        setcolor(4);
        outtextxy(midx-295,midy+180,message1);
        setcolor(15);
        o=counter%6;
        sprintf(message3, "BALLS: %d",o);
        outtextxy(midx+15,midy+200,message3);
        delay(10);
        cleardevice();
    }
z:
    setbkcolor(0);
    cleardevice();
    setcolor(12);
    if(pctosswin%4==0||pctosswin%4==2)
    {
        if(toss_win==49)
            outtextxy(100,80,"FIRST INNIGS END");
        if(toss_win==50)
            outtextxy(100,80,"SECOND INNIGS END");
        setcolor(10);
        sprintf(message, "YOUR SCORE: %d/%d",run,wicket);
        outtextxy(100,100,message);
        setcolor(7);
        if(toss_win==49)
            outtextxy(200,250,"press any key to continue second innings....");
        if(toss_win==50)
            outtextxy(200,250,"press any key to continue....");
        //getch();
        getch();
        cleardevice();
        if(toss_win==49)
        {
            Autoplay();
            setcolor(12);
            outtextxy(100,80,"SECOND INNIGS END");
            sprintf(messageap, "PC SCORE : %d/%d",pcrun,pcwicket);
            setcolor(14);
            outtextxy(100,120,messageap);
            setcolor(7);
            outtextxy(200,250,"press any key to continue....");
            //getch();
            getch();
            cleardevice();
        }
    }
    if(pctosswin%4==3)
    {
        outtextxy(100,80,"FIRST INNIGS END");
        setcolor(10);
        sprintf(message, "YOUR SCORE: %d/%d",run,wicket);
        outtextxy(100,100,message);
        setcolor(7);
        outtextxy(200,250,"press any key to continue second innings....");
        //getch();
        getch();
        cleardevice();
        Autoplay();
        setcolor(12);
        outtextxy(100,80,"SECOND INNIGS END");
        sprintf(messageap, "PC SCORE : %d/%d",pcrun,pcwicket);
        setcolor(14);
        outtextxy(100,120,messageap);
        setcolor(7);
        outtextxy(200,250,"press any key to continue....");
        //getch();
        getch();
        cleardevice();
    }
    if(pctosswin%4==1)
    {
        outtextxy(100,80,"SECOND INNIGS END");
        setcolor(10);
        sprintf(message, "YOUR SCORE: %d/%d",run,wicket);
        outtextxy(100,100,message);
        setcolor(7);
        outtextxy(200,250,"press any key to continue....");
        //getch();
        getch();
        cleardevice();
    }

    char pcscore[15],myscore[15];
    setcolor(9);
    outtextxy(200,50,"STATISTICS");
    setcolor(6);
    sprintf(myscore, "YOUR SCORE: %d/%d",run,wicket);
    outtextxy(100,140,myscore);
    sprintf(pcscore, "PC SCORE : %d/%d",pcrun,pcwicket);
    outtextxy(100,170,pcscore);
    setcolor(1);
    outtextxy(200,250,"press any key for result");
    //getch();
    getch();
    cleardevice();
    setcolor(2);
    {
        if(run>pcrun)
        {
            outtextxy(midx-90,midy-140,"CONGRATULATION");
            outtextxy(midx-90,midy-100,"YOU HAVE WON THE MATCH");
            setcolor(12);
            circle(midx,midy,25);
            setfillstyle(10,14);
            floodfill(midx,midy,12);
            setfillstyle(1,14);
            bar(midx-12,midy+21,midx-8,midy+80);
            bar(midx+10,midy+19,midx+14,midy+80);
            rectangle(midx-25,midy+80,midx+25,midy+100);
            setfillstyle(10,14);
            floodfill(midx-21,midy+90,12);
            //getch();
            getch();
        }
        else if(pcrun==run)
        {
            outtextxy(midx-100,midy-100," THE MATCH IS DRAW");
            //getch();
            getch();
        }
        else
        {
            setcolor(10);
            outtextxy(280,140,"SORRY");
            outtextxy(280,170,"YOU LOSS");
            //getch();
            getch();
        }
    }
    cleardevice();
    setcolor(15);
    outtextxy(midx-50,midy,"THANK YOU");
    getch();
    //getch();
    cleardevice();
    pctosswin++;
    goto start;
ex:
    closegraph();
    return 0;
}


