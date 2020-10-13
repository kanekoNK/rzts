#include<stdio.h>
#include<drawlib.h>
#include<time.h>
#include<stdlib.h>
int cdraw();
int cmove();
int kcase(int b);
int Dup();
int Sup();
int Fset();
int FLA();
int Fsta();
int Fsw();
void Timecou();
void End();
void OP();
//**********************キャラクターのドット絵**********************
int MC[4][18][14] = {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,3,3,3,3,3,0,0,0,0,0},
			  {0,0,0,3,3,3,3,3,3,3,3,3,3,0},
			  {0,0,0,1,1,1,2,2,1,2,0,0,0,0},
			  {0,0,1,2,1,2,2,2,1,2,2,2,0,0},
	                  {0,0,1,2,1,1,2,2,2,1,2,2,2,0},
			  {0,0,1,1,2,2,2,2,1,1,1,1,0,0},
			  {0,0,0,0,2,2,2,2,2,2,2,0,0,0},
			  {0,0,0,1,1,3,1,1,1,0,0,0,0,0},
			  {0,0,1,1,1,3,1,1,3,1,1,1,0,0},
			  {0,1,1,1,1,3,3,3,3,1,1,1,1,0},
			  {0,2,2,1,3,2,3,3,2,3,1,2,2,0},
			  {0,2,2,2,3,3,3,3,3,3,2,2,2,0},
			  {0,2,2,3,3,3,3,3,3,3,3,2,2,0},
			  {0,0,0,3,3,3,0,0,3,3,3,0,0,0},
			  {0,0,1,1,1,0,0,0,0,1,1,1,0,0},
			  {0,1,1,1,1,0,0,0,0,1,1,1,1,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
            		 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			  {0,0,0,0,3,3,3,3,3,0,0,0,0,0},
			  {0,0,0,3,3,3,3,3,3,3,3,3,3,0},
			  {0,0,0,1,1,1,2,2,1,2,0,0,0,0},
	                  {0,0,1,2,1,2,2,2,1,2,2,2,0,0},
			  {0,0,1,2,1,2,2,2,2,1,2,2,2,0},
			  {0,0,1,1,2,2,2,2,1,1,1,1,0,0},
			  {0,0,0,0,2,2,2,2,2,2,2,0,0,0},
			  {0,0,0,1,1,1,1,3,1,2,2,0,0,0},
			  {0,0,2,1,1,1,1,1,1,2,2,2,0,0},
			  {0,2,2,1,1,1,1,1,1,2,2,0,0,0},
			  {0,1,1,3,3,3,3,3,3,3,0,0,0,0},
			  {0,1,3,3,3,3,3,3,3,3,0,0,0,0},
			  {1,1,3,3,3,3,0,3,3,0,0,0,0,0},
			  {1,0,0,0,0,0,1,1,1,0,0,0,0,0},
			  {0,0,0,0,0,0,1,1,1,1,0,0,0,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
			 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,3,3,3,3,3,0,0,0,0,0},
			  {0,0,0,3,3,3,3,3,3,3,3,3,3,0},
			  {0,0,0,1,1,1,2,2,1,2,0,0,0,0},
			  {0,0,1,2,1,2,2,2,1,2,2,2,0,0},
	                  {0,0,1,2,1,1,2,2,2,1,2,2,2,0},
			  {0,0,1,1,2,2,2,2,1,1,1,1,0,0},
			  {0,0,0,0,2,2,2,2,2,2,2,0,0,0},
			  {0,1,1,1,1,3,3,1,1,0,0,0,0,0},
			  {2,1,1,1,1,3,3,3,1,1,1,2,2,2},
			  {2,2,0,1,1,3,2,3,3,3,1,1,2,2},
			  {0,0,0,3,3,3,3,3,3,3,0,0,1,0},
			  {0,0,3,3,3,3,3,3,3,3,3,1,1,0},
			  {0,3,3,3,3,3,3,3,3,3,3,1,1,0},
			  {1,1,3,3,3,0,0,0,3,3,3,1,1,0},
			  {1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			  {0,1,1,1,0,0,0,0,0,0,0,0,0,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
                         {{0,0,0,0,0,0,0,0,0,0,0,2,2,2},
		          {0,0,0,0,3,3,3,3,3,0,0,2,2,2},
			  {0,0,0,3,3,3,3,3,3,3,3,3,3,2},
			  {0,0,0,1,1,1,2,2,1,2,0,1,1,1},
			  {0,0,1,2,1,2,2,2,1,2,2,2,1,1},
	                  {0,0,1,2,1,1,2,2,2,1,2,2,2,1},
			  {0,0,1,1,2,2,2,2,1,1,1,1,1,0},
			  {0,0,0,0,2,2,2,2,2,2,2,1,0,0},
			  {0,0,0,1,1,3,1,1,1,3,1,0,0,0},
			  {0,0,1,1,1,1,3,1,1,1,3,0,0,1},
			  {2,2,1,1,1,1,3,1,1,1,3,0,0,1},
			  {2,2,2,3,3,3,3,3,2,3,3,3,1,1},
			  {2,2,0,3,3,3,3,3,3,3,3,3,1,1},
			  {0,0,1,1,3,3,3,3,3,3,3,3,1,1},
			  {0,1,1,3,3,3,3,3,3,0,0,0,0,0},
			  {1,1,1,3,3,3,0,0,0,0,0,0,0,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};
	
	char CR[5][10] = {"white","black","yellow","red","blue"};
	char CRa[5][10] = {"red","white","white"};
	int ik[2][14] = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13},
		         {13,12,11,10,9,8,7,6,5,4,3,2,1,0}};
	int f=0, e=0, id = 150, xx = 100, FR= 0;
	int cou = 0, b;
	int Dp[10] = {35, 55, 70, 75, 80, 75, 70, 55, 35};
	int Sp[6]={20,35,40,35,20,0};
	int Kai = 1, bf=0;
	int Stats[2][600]={0};
	int Sou = 0;
	int Kaix[2] = {150, 350};
	int STAtime=0, MIDtime=0, ENDtime=0;
	int tal[40] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
	char EndBN[] = "Press Enter to exit";
	char sscore[] = "   :   ";
	int score1 = 0, score2 = 0, bh=0;
	double time3;
int main(void)
{
	dl_initialize(1.0);
	dl_clear(DL_C(CR[0]));
	int i, k, x = 0, y = 0,hn=0;
	int a, c, d, upc = 0;
	int slp = 0;
	float tm = 0.2;
	OP();
	dl_clear(DL_C("white"));
	time_t time1, time2;//******
	time(&time1);//*******
	Fset();	
	while(1){
		time(&time2);//*********
		time3 = difftime(time2, time1);//*******
		Timecou();
		FLA();
//****************************キーの受付（マウス）************************************************
		if(FR == 0){
			if(slp <= 0){
				while(dl_get_event(&a, &b, &c, &d)){
					if(b == 'w'){
						slp = 7 + bh;
						bh=2;
					}
					else if(b == 'q'){

						slp = 5 + bh;
						bh=0;
					}
				}
			}
			slp--;
		}
		else{		
		}
//*******************************idou
		cmove();
//*********************************************キャラクターの描画*************************************
		dl_stop();
		kcase(b);
		bf = b;
		Fsw();


					
	}
	return 0;
}
void OP(){
	int a, c, d;
	dl_clear(DL_C("black"));
	dl_rectangle(0, 0, 640, 480, DL_C("red"), 10, 0);
	dl_text ("RUN JUMP", 100, 100, 2.0, DL_C("red"), 4);
	dl_text ("Q = SMALL JUMP", 100, 150, 1.0, DL_C("red"), 2);
	dl_text ("W = BIG   JUMP", 100, 200, 1.0, DL_C("red"), 2);
	dl_text ("Press the Enter key", 150, 300, 0.8, DL_C("red"), 2);
	while(1){
	dl_get_event(&a, &b, &c, &d);
	if(b == '\n')
		break;
	}				
}
void End(){
	char EndBN2[] = "TIME";
	int a, b, c, d;
	dl_rectangle(40, 90, 600, 310, dl_color_from_name(CR[3]), 1, 1);
	dl_rectangle(50, 100, 590, 300, dl_color_from_name(CR[1]), 1, 1);
	dl_text (EndBN2, 100, 150, 1.2, DL_C("white"), 2);
	dl_text ("Rank", 120, 180, 0.5, DL_C("white"), 2);
	if(score1==0 && score2 < 45)
		dl_text ("C", 150, 240, 2.0, DL_C("white"), 2);	
	else if(score1 == 0 && score2 >= 45)
		dl_text ("B", 150, 240, 2.0, DL_C("white"), 2);
	else if(score1 == 1 && score2 < 30)
		dl_text ("A", 150, 240, 2.0, DL_C("white"), 2);
	else
		dl_text ("S", 150, 240, 2.0, DL_C("white"), 2);	
	dl_text (sscore, 280, 150, 1.2, DL_C("white"), 2);
	dl_text (EndBN, 320, 280, 0.8, DL_C("white"), 2);
	while(1){
		dl_get_event(&a, &b, &c, &d);
		if(b == '\n')
			exit(0);
	}
}
void Timecou(){
	double tisa = 0;
	if(tisa != time3){
		sprintf (sscore, "%3d:%2d", score1, score2);
		dl_text (sscore, 10, 20, 0.8, DL_C("white"), 2);
		tisa = time3;		
		if(time3 >= 60){
			score1 = time3 / 60;
			score2 = time3 - 60 * score1; 
		}
		else{
			score1 = 0;
			score2 = time3;
		}
		sprintf (sscore, "%3d:%2d", score1, score2);
		dl_text (sscore, 10, 20, 0.8, DL_C("red"), 2);
	}
}
int Fsw(){
	int COU=0;
	if(FR==0){
		while(Stats[Sou][id+COU] > 1){
			COU=COU+5;
			if(COU > 25){
				Kai = 1;
				Sou = 1;
			}
		}
	}
			
}
int Fsta(){
	int Zn = -2, Bn = 29;
	int i;
	if(e == 0){
		dl_rectangle(id-2, Kaix[Sou], id+3, Kaix[Sou]+10, dl_color_from_name(CRa[Stats[Sou][id]]), 1, 1);
		if(Stats[Sou][id] == 0){
			Stats[Sou][id] = 1;			
		}
		else if(Stats[Sou][id] > 0){
			Stats[Sou][id] = 2;
		}
	}	
	else{
		dl_rectangle(id+29, Kaix[Sou], id+34, Kaix[Sou]+10, dl_color_from_name(CRa[Stats[Sou][id+30]]), 1, 1);
		if(Stats[Sou][id+30] == 0){
			Stats[Sou][id+30] = 1;						
		}
		else if(Stats[Sou][id+30] > 0){
			Stats[Sou][id+30] = 2;		
		}
	}
}
int FLA(){
	int k, i, x=0,y=0,l=0;
	int FX;
	FX = xx;
	dl_stop();
	if(Kai > 0){
		if(xx+36 < 150){
			while(xx+36 < 150){
				dl_stop();
				for(k = 0; k < 17; k++){
					for(i = 0; i < 13; i++){
						dl_rectangle(y*2+id, x*2+xx, y*2+1+id,x*2+1+xx, dl_color_from_name(CR[MC[3][k][ik[e][i]]]), 1, 1);
						y++;
					}
					y=0;
					x++;
				}
				x=0;
				l++;
				dl_resume();
				dl_wait(0.1);
				dl_rectangle(id,xx, 28+1+id, xx+36+1, dl_color_from_name(CR[0]), 1, 1);
				xx=xx+10;				
			}
			Kai=0;
			xx=116;
		}
		else if(xx + 36 < 350){
			while(xx + 36 < 350){
				dl_stop();
				for(k = 0; k < 17; k++){
					for(i = 0; i < 13; i++){
						dl_rectangle(y * 2 + id, x * 2 + xx, y * 2 + 1 + id, x * 2 + 1 + xx, dl_color_from_name(CR[MC[3][k][ik[e][i]]]), 1, 1);
						y++;
					}
					y=0;
					x++;	
				}
				x=0;
				dl_resume();
				dl_wait(0.1);
				dl_rectangle(id, xx, 28+ 1+id, 36+1+xx, dl_color_from_name(CR[0]), 1, 1);
				xx=xx+10;		      					
			}
			Kai=0;
			xx = 314;
			Sou = 1;			
		}
		else{
			while(xx+36 < 430){
				dl_stop();
				for(k = 0; k < 17; k++){
					for(i = 0; i < 13; i++){
						dl_rectangle(y * 2 + id, x * 2 + xx, y * 2 + 1 + id, x * 2 + 1 + xx, dl_color_from_name(CR[MC[3][k][ik[e][i]]]), 1, 1);
						y++;
					}
					y=0;
					x++;	
				}
				x=0;
				dl_wait(0.1);
				dl_resume();
				dl_rectangle(id, xx, 28 + 1 + id, 36+ 1 + xx, dl_color_from_name(CR[0]), 1, 1);
				xx=xx+10;		        					
			}
			Kai=0;
			xx = 430;
			End();			
		}
	}
}


int Fset(){
	dl_rectangle(94, 0, 144, 480, dl_color_from_name(CR[1]), 1, 1);
	dl_rectangle(535, 0, 585, 480, dl_color_from_name(CR[1]), 1, 1);
	dl_rectangle(143, 150, 535, 160, dl_color_from_name(CR[1]), 1, 1);
	dl_rectangle(143, 350, 535, 360, dl_color_from_name(CR[1]), 1, 1);
}
int kcase(int b){

	switch(b){
		case 'w':
			
			FR = 1;
			Dup();
			dl_resume();
			dl_wait(0.1);
			dl_rectangle(id, xx - Dp[cou-1], 28 + 1 + id, 32+ 1 + xx - Dp[cou-1], dl_color_from_name(CR[0]), 1, 1);				
			break;
		case 'q':
			FR = 1;
			Sup();
			dl_resume();
			dl_wait(0.1);
			dl_rectangle(id, xx - Sp[cou-1], 28 + 1 + id, 32+ 1 + xx - Sp[cou-1], dl_color_from_name(CR[0]), 1, 1);
			break;
		default:
			bf=10;
			cdraw();
			dl_resume();
			dl_wait(0.1);			
			dl_rectangle(id, xx, 28 + 1 + id, 32+ 1 + xx, dl_color_from_name(CR[0]), 1, 1);
			Fsta();
		break; 
	}
}
int Dup(){
	int k, i, x=0,y=0;
		for(k = 0; k < 17; k++){
			for(i = 0; i < 13; i++){
				dl_rectangle(y * 2 + id, x * 2 + xx - Dp[cou], y * 2 + 1 + id, x * 2 + 1 + xx - Dp[cou], dl_color_from_name(CR[MC[3][k][ik[e][i]]]), 1, 1);
				y++;
			}
			y=0;
			x++;	
		}
		cou++;
		if(cou > 9){
			cou = 0;
			FR = 0;
			b = 0;
		}				
}
	
int Sup(){
	
	int k, i, x=0,y=0;
	for(k = 0; k < 17; k++){
		for(i = 0; i < 13; i++){
			dl_rectangle(y * 2 + id, x * 2 + xx - Sp[cou], y * 2 + 1 + id, x * 2 + 1 + xx - Sp[cou], dl_color_from_name(CR[MC[3][k][ik[e][i]]]), 1, 1);
			y++;
		}
		y=0;
		x++;	
	}
	cou++;
	if(cou > 5){
		cou = 0;
		FR = 0;
		b = 0;
	}				
}
	

int cmove(){
			if(id > 500){
				e = 1;
			}
				else if(id < 150){
					e = 0;
					if(FR==0){
						dl_rectangle(145, Kaix[Sou], 150, Kaix[Sou]+10, dl_color_from_name(CR[3]), 1, 1);
					}
				
			}
			if(e == 1){
			id = id - 5;
			}
			else{
			id = id + 5;
			}	
			f++;
			if(f>2){
				f = 1;
			}
}
int cdraw(){
	int k, i, x=0,y=0;
		for(k = 0; k < 17; k++){
			for(i = 0; i < 13; i++){
				dl_rectangle(y * 2 + id, x * 2 + xx, y * 2 + 1 + id, x * 2 + 1 + xx, dl_color_from_name(CR[MC[f][k][ik[e][i]]]), 1, 1);
				y++;
			}
			y=0;
			x++;	
		}			
}


