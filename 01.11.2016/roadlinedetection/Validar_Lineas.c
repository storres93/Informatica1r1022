
#include "Header.h"

#define 	VAL_MIN_FRAMES		4
#define		VAL_NO_LINE		6

#define		DELTA_RHO		10
#define		DELTA_THETA		0.15

void LimpiarLinea ( Linea * line)
{
  line->punto1.x=0;
  line->punto1.y=0;
  line->punto2.x=0;
  line->punto2.y=0;
  line->rho=0;
  line->theta=0;
}

int  CompareLines (Linea *Line1,Linea * Line2 )
{
  float delta_rho = Line1->rho - Line2->rho;
  float delta_theta = Line1->theta - Line2->theta;
  
//  printf("delta_rho %f delta_theta %f \n",delta_rho,delta_theta);
	    
  if ( delta_rho < DELTA_RHO && delta_rho > -DELTA_RHO)
  {
    if ( delta_theta < DELTA_THETA && delta_theta > -DELTA_THETA) 
    {
      return 1;
    }
  }
  return 0;
}



void Validar_Lineas (Linea * line , Linea * line_ret)
{
  
  static Linea  Lineas_Estables[3] ={ {{0,0},{0,0},0,0},{{0,0},{0,0},0,0},{{0,0},{0,0},0,0} };
  static Linea  Lineas_Inestables[3] = { {{0,0},{0,0},0,0},{{0,0},{0,0},0,0},{{0,0},{0,0},0,0} };
  static  int   Cnt_inestables[3] = { 0,0,0 };
  static  int   Cnt_NoLine[3] = { 0,0,0 };
  
  int i=0;
  
  for (i=0;i<3;i++)
  {
      if (line[i].rho) //Si se detecto linea
      {
	Cnt_NoLine[i]=0;
	if ( CompareLines (&line[i],&Lineas_Estables[i])) 
	{
	  Lineas_Estables[i]=line[i];
	}
	
	else
	{
	  if ( CompareLines(&line[i],&Lineas_Inestables[i]) )
	  {
	    Lineas_Inestables[i] = line[i];
	    Cnt_inestables[i] += 1;
	    if ( Cnt_inestables[i] >= VAL_MIN_FRAMES)
	    {
	      Lineas_Estables[i]= line[i];
	      Cnt_NoLine[i]=0;
	    }
	  }
	  
	  else
	  {
	    Lineas_Inestables[i] = line[i];
	    Cnt_inestables[i]= 0;
	  }
	  
	}
      }
      else  //No se detecto linea
      {
	if (Cnt_NoLine[i] >= VAL_NO_LINE ) 
	{
	  LimpiarLinea (&Lineas_Estables[i]);
	}
	else Cnt_NoLine[i] += 1;
      }
  }
  
    
  if ( CompareLines (&Lineas_Estables[1],&Lineas_Estables[0]) )
  {
    LimpiarLinea (&Lineas_Estables[0]);
  }
  
  if ( CompareLines (&Lineas_Estables[1],&Lineas_Estables[2]) )
  {
    LimpiarLinea (&Lineas_Estables[2]);
  }
  
  
  
  
  for (i=0;i<3;i++)
  {
    line_ret[i] = Lineas_Estables[i];
  }
  
  return;
  
}
  
  /*

%%
if (size(New_Center,2))
    Cnt_NoLinea_Center = 0;
    if ( CompareLines (New_Center,Linea_Estable_Center))
        Linea_Estable_Center = New_Center;
        Cnt_NoLinea_Center = 0;
        
        %Si pasa de un sector a otro
        % De Derecha al centro
    elseif ( CompareLines (New_Center,Linea_Estable_Right))
        Linea_Estable_Center = New_Center;
        Linea_Estable_Right = [];
        Cnt_NoLinea_Center = 0;
        
        % De izq al centro
    elseif ( CompareLines (New_Center,Linea_Estable_Left))
        Linea_Estable_Center = New_Center;
        Linea_Estable_Left = [];
        Cnt_NoLinea_Center = 0;
        
        
   
    
    %Si no hay linea
else
    if (Cnt_NoLinea_Center >= cantidad_NoLine)
        Linea_Estable_Center = [];
    else
        Cnt_NoLinea_Center =  Cnt_NoLinea_Center + 1;
    end
end
%%
if (size(New_Left,2))
    if ( CompareLines (New_Left,Linea_Estable_Left))
        Linea_Estable_Left = New_Left;
        Cnt_NoLinea_Left = 0;
        
        
        %Si pasa del centro a la izq
    elseif ( CompareLines (New_Left,Linea_Estable_Center))
        Linea_Estable_Left = New_Left;
        Linea_Estable_Center = [];
        Cnt_NoLinea_Left = 0;
        
        
    else
        if (CompareLines(New_Left,Linea_Inestable_Left))
            
            Linea_Inestable_Left = New_Left;
            Cnt_Linea_Inestable_Left= Cnt_Linea_Inestable_Left + 1;
            
            if ( Cnt_Linea_Inestable_Left >= cantidad_requerida)
                Linea_Estable_Left = New_Left;
                Cnt_NoLinea_Left = 0;
                
            end
        else
            Linea_Inestable_Left = New_Left;
            Cnt_Linea_Inestable_Left= 1;
        end
    end
else
    if (Cnt_NoLinea_Left >= cantidad_NoLine)
        Linea_Estable_Left = [];
    else
        Cnt_NoLinea_Left =  Cnt_NoLinea_Left + 1;
    end
end

%%
if (size(New_Right,2))
    if ( CompareLines (New_Right,Linea_Estable_Right))
        Linea_Estable_Right = New_Right;
        Cnt_NoLinea_Right = 0;
        
        
        %Si pasa del centro a la derecha
    elseif ( CompareLines (New_Right,Linea_Estable_Center))
        Linea_Estable_Right = New_Right;
        Linea_Estable_Center = [];
        Cnt_NoLinea_Right = 0;
        
    else
        if (CompareLines(New_Right,Linea_Inestable_Right))
            Linea_Inestable_Right = New_Right;
            Cnt_Linea_Inestable_Right= Cnt_Linea_Inestable_Right + 1;
            
            if ( Cnt_Linea_Inestable_Right >= cantidad_requerida)
                Linea_Estable_Right = New_Right;
                Cnt_NoLinea_Right = 0;
            end
        else
            Linea_Inestable_Right = New_Right;
            Cnt_Linea_Inestable_Right= 1;
        end
    end
else
    if (Cnt_NoLinea_Right >= cantidad_NoLine)
        Linea_Estable_Right = [];
    else
        Cnt_NoLinea_Right =  Cnt_NoLinea_Right + 1;
    end
end

lines_Ok = [ Linea_Estable_Left Linea_Estable_Center Linea_Estable_Right ];
end

*/
  