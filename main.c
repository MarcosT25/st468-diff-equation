// @author: Marcos Takahashi
// @school: Universidade Estadual de Campinas

#include <stdio.h>
#include <math.h>

int main ( void )
{
    FILE  *plotFile ;
    
    int i, Nt ;
    
    double t, ti, tf, dt, sgm, ro, beta ;
    
    ti = 0.0 ; tf = 5.0 ; dt = 0.001 ;
    
    Nt = (int) ( tf/dt - ti/dt + 1 ) ;
    
    double x[Nt], y[Nt], z[Nt] ;
    
    sgm = 11.0 ; ro = 28.0 ; beta = 8/3 ;
    
    plotFile = fopen("plotfile.csv","w") ;

    
// condicoes iniciais
    
    t = ti ;
    
    x[0] = 1.5 ;
    
    y[0] = -1.5 ;

    z[0] = 25.5 ;
    
// plotando o grafico
    
    i = 0 ;
    
    do {
        
        t = ti + (double)(i) * dt ;
        
        x[i+1] = x[i] + ( sgm * ( y[i] - x[i] ) ) * dt ;
        
        y[i+1] = y[i] + ( x[i] * (ro - z[i]) - y[i] ) * dt ;

        z[i+1] = z[i] + ( x[i] * y[i] - beta * z[i] ) * dt ;
        
        fprintf( plotFile, "%lf, %lf, %lf, %lf \n", t, x[i], y[i], z[i] ) ;
        
        i++ ;
        
    } while ( i < Nt );

}