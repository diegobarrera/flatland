#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <sstream>


#include "Point.h"

std::list<Point>  search (std::string word,std::string operador, int num, const std::list< std::list<Point>::iterator > & listaOrdenamiento);
bool openFiles (std::list<Point>  &flatland ,   std::list< std::list<Point>::iterator > &listaN,   std::list< std::list<Point>::iterator > &listaC,   std::list< std::list<Point>::iterator > &listaA,   std::list< std::list<Point>::iterator > &listaY);

template <class C>
std:: string toString(const C& dato)
{
    std:: stringstream flujo;
    flujo << dato;
  return(flujo.str());
}

int main(int argc, char* argv[])
{

  std::list<Point> flatland;
  std::list<std::list<Point>::iterator> listaN,listaC,listaA,listaY;

    if( ! openFiles(flatland,listaN,listaC,listaA,listaY) )
	  std::cout<<"Error abriendo los archivos!"<<std::endl;


	int menu=0;
    do
    {
       	std::cout<<"Bienvenido! "<<std::endl;
  		std::cout<<"----------------------------"<<std::endl;
    	std::cout<<"1.Buscar "<<std::endl;
    	std::cout<<"2. "<<std::endl;
    	std::cout<<"3. Buscar ruta "<<std::endl;
    	std::cout<<"4. "<<std::endl;
    	std::cout<<"0.Salir "<<std::endl;
    	  std::cin>>menu;

    	if(menu==1)
    	{
    	    int submenu=0;
    	    std::cout<<" 1.Nombre"<<std::endl;
    	    std::cout<<" 2.Capacidad de atencion"<<std::endl;
    	    std::cout<<" 3.Area"<<std::endl;
    	    std::cout<<" 4.Antigüedad"<<std::endl;
    	    std::cout<<" 0.Salir"<<std::endl;
    	      std::cin>>submenu;

    	    std::string word;
    	    std::string operador;

    	    if(submenu==1)
    	    {
                std::cout<<"Ingrese el nombre del lugar: "<<std::endl;
                    std::cin>>word;
                std::cout<<"Ingrese el operador ( < , <= , = , >= , > )"<<std::endl;
                    std::cin>>operador;

                search(word,operador,1,listaN);
            }

    	    else if(submenu==2)
    	    {
                std::cout<<"Ingrese la capacidad de atención: "<<std::endl;
                    std::cin>>word;
                std::cout<<"Ingrese el operador ( < , <= , = , >= , > )"<<std::endl;
                    std::cin>>operador;

                search(word,operador,2,listaC);
            }

    	    else if(submenu==3)
    	    {
                std::cout<<"Ingrese el área del lugar: "<<std::endl;
                    std::cin>>word;
                std::cout<<"Ingrese el operador ( < , <= , = , >= , > )"<<std::endl;
                    std::cin>>operador;

                search(word,operador,3,listaA);
            }

    	    else if(submenu==4)
    	    {
                std::cout<<"Ingrese la antigüedad: "<<std::endl;
                    std::cin>>word;
                std::cout<<"Ingrese el operador ( < , <= , = , >= , > )"<<std::endl;
                    std::cin>>operador;

                search(word,operador,4,listaY);
            }
    	}

    	else if(menu==2)
    	{
    	}

    	else if(menu==3)
    	{
    	}

    	else if(menu==4)
    	{
    	}

    	else if(menu==5)
    	{
    	}

    }while( menu!=0 );


  std::cout<<"Gracias por usar nuestros servicios!"<<std::endl;

  return(0);

}//main



bool openFiles (std::list<Point>  &flatland , std::list< std::list<Point>::iterator > &listaN, std::list< std::list<Point>::iterator > &listaC
, std::list< std::list<Point>::iterator > &listaA,  std::list< std::list<Point>::iterator > &listaY)
{

    std::ifstream inCoordenates("coordenates.txt");
    std::ifstream inInterest("interest.txt");

    int nC;

//    std::list< std::list<Point>::iterator > listaOrdenamiento;

    if(inCoordenates.is_open() && inInterest.is_open())
    {
        inCoordenates >> nC;

        for(int i=0 ; i<nC ; i++ )
        {
                char line[1000];
//            std::string line;
            float x=0, y=0;

            inCoordenates >> x >> y;
            inInterest >> line;

            //Place auxPlace();
             //char* p = std::strtok( line ,"|");

                std::string name= strtok( line ,"|");
                double capacity= atof(strtok( line ,"|"));
                double area= atof( strtok( line ,"|") );
                double year= atof(strtok( line ,"|"));

                
                std::string serv= strtok( line ,"|");
                Service s(serv,0);
                std::list<Service> service;
                service.push_back(s);
                
                    Place auxPlace(name,capacity,area,year,service);//constructor clase Place

                    //Point auxPoint(toString(i),x,y,auxPlace); //constructor clase Ponit
                    Point auxPoint;
                    auxPoint.setId(toString(i));
                    auxPoint.setX(x);
                    auxPoint.setY(y);
                    auxPoint.setPlace(auxPlace);

                    flatland.push_back(auxPoint);

                    std::list<Point>::iterator aux = flatland.end();
                    //listaOrdenamiento.push_back(aux);


        bool bn=false,bc=false,ba=false,by=false;
        for(unsigned int i=1 ; i<flatland.size() ; i++)
        {
            std::list< std::list<Point>::iterator >::iterator it,jt;

            if(!bn)
            {
                if(!listaN.empty())
                {
                    it = listaN.begin();
                    advance(it,i);
                    jt=it;

                    if(it!=listaN.end())
                        jt++;

                    if(it==jt)
                    {
                       if(aux->getPlace().getName() < (**it).getPlace().getName())
                          listaN.insert(it,aux);
                       else
                           listaN.insert(++it,aux);
                       bn=true;
                    }
                    else if(aux->getPlace().getName()>(**it).getPlace().getName() && aux->getPlace().getName()<(**jt).getPlace().getName())
                    {
                        listaN.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getName()<(**it).getPlace().getName() && aux->getPlace().getName()<(**jt).getPlace().getName())
                    {
                        listaN.insert(it,aux);
                        bn=true;
                    }
                }
                else
                {
                   listaN.push_back(aux);
                   bn=true;
                }
            }

            if(!bc)
            {
                if(!listaC.empty())
                {
                    it = listaC.begin();
                    advance(it,i);
                    jt=it;

                    if(it!=listaC.end())
                        jt++;

                    if(it==jt)
                    {
                       if(aux->getPlace().getCapacity() < (**it).getPlace().getCapacity())
                          listaC.insert(it,aux);
                        else
                           listaC.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getCapacity()>(**it).getPlace().getCapacity() && aux->getPlace().getCapacity()<(**jt).getPlace().getCapacity())
                    {
                        listaC.insert(++it,aux);
                        bn=true;
                    }
                   else if(aux->getPlace().getCapacity()<(**it).getPlace().getCapacity() && aux->getPlace().getCapacity()<(**jt).getPlace().getCapacity())
                    {
                        listaC.insert(it,aux);
                        bn=true;
                    }
                }
                else
                {
                   listaC.push_back(aux);
                   bn=true;
                }
            }

            if(!ba )
            {
                if(!listaA.empty())
                {
                    it=listaA.begin();
                    advance(it,i);
                    jt=it;

                    if(it!=listaA.end())
                        jt++;

                    if(it==jt)
                    {
                       if(aux->getPlace().getArea() < (**it).getPlace().getArea())
                          listaA.insert(it,aux);
                        else
                           listaA.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getArea()>(**it).getPlace().getArea() && aux->getPlace().getArea()<(**jt).getPlace().getArea())
                    {
                        listaA.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getArea()<(**it).getPlace().getArea() && aux->getPlace().getArea()<(**jt).getPlace().getArea())
                    {
                        listaA.insert(it,aux);
                        bn=true;
                    }
                }
                else
                {
                    listaA.push_back(aux);
                    bn=true;
                }


            }

            if(!by)
            {
                if(!listaY.empty())
                {
                    it=listaY.begin();
                    advance(it,i);
                    jt=it;

                    if(it!=listaY.end())
                        jt++;

                    if(it==jt)
                    {
                       if(aux->getPlace().getYear() < (**it).getPlace().getYear())
                          listaY.insert(it,aux);
                        else
                           listaY.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getYear()>(**it).getPlace().getYear() && aux->getPlace().getYear()<(**jt).getPlace().getYear())
                    {
                        listaY.insert(++it,aux);
                        bn=true;
                    }
                    else if(aux->getPlace().getYear()<(**it).getPlace().getYear() && aux->getPlace().getYear()<(**jt).getPlace().getYear())
                    {
                        listaY.insert(it,aux);
                        bn=true;
                    }
                }
                else
                {
                    listaY.push_back(aux);
                    bn=true;
                }
            }
        }

       }
      inCoordenates.close();
      inInterest.close();

    return true;
    }

 return false;

}


std::list<Point>  search (std::string word,std::string operador, int num, const std::list< std::list<Point>::iterator > & listaOrdenamiento)
{

    std::list< std::list<Point>::iterator >::const_iterator i;
    std::list<Point> listaNueva;

    //std::list< std::list<Point>::iterator > copiaNombre = listaOrdenamiento.list(listaOrdenamiento.size());

    if(num==1) //busqueda por nombre
    {
        for( i=listaOrdenamiento.begin() ; i!=listaOrdenamiento.end() ; i++ )
        {
                if(operador=="<" && (**i).getPlace().getName() < word)
                    listaNueva.push_back(**i);
                if(operador=="<=" && (**i).getPlace().getName() <= word)
                    listaNueva.push_back(**i);
                if(operador=="=" && (**i).getPlace().getName() == word)
                    listaNueva.push_back(**i);
                if(operador==">=" && (**i).getPlace().getName() > word)
                    listaNueva.push_back(**i);
                if(operador==">" && (**i).getPlace().getName() > word)
                    listaNueva.push_back(**i);
        }
    }
    else if(num==2) //busqueda por capacidad
    {
        for( i=listaOrdenamiento.begin() ; i!=listaOrdenamiento.end() ; i++ )
        {
                if(operador=="<" && (**i).getPlace().getCapacity() <  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="<=" && (**i).getPlace().getCapacity() <=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="=" && (**i).getPlace().getCapacity() ==  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">=" && (**i).getPlace().getCapacity() >=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">" && (**i).getPlace().getCapacity() >  atof(word.c_str()))
                    listaNueva.push_back(**i);
        }
    }
    else if(num==3) //busqueda por área
    {
        for( i=listaOrdenamiento.begin() ; i!=listaOrdenamiento.end() ; i++ )
        {
                if(operador=="<" && (**i).getPlace().getArea() <  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="<=" && (**i).getPlace().getArea() <=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="=" && (**i).getPlace().getArea() ==  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">=" && (**i).getPlace().getArea() >=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">" && (**i).getPlace().getArea() >  atof(word.c_str()))
                    listaNueva.push_back(**i);
        }
    }
    else if(num==4) //busqueda por antigüedad
    {
        for( i=listaOrdenamiento.begin() ; i!=listaOrdenamiento.end() ; i++ )
        {
                if(operador=="<" && (**i).getPlace().getYear() <  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="<=" && (**i).getPlace().getYear() <=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador=="=" && (**i).getPlace().getYear() ==  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">=" && (**i).getPlace().getYear() >=  atof(word.c_str()))
                    listaNueva.push_back(**i);
                if(operador==">" && (**i).getPlace().getYear() > atof(word.c_str()))
                    listaNueva.push_back(**i);
        }
    }
    return listaNueva;
}
