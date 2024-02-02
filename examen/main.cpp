#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

void main()
{
	cout << "Bienvenido a mi ahorcado" << endl;
	cout << endl;

	//Hago un vector de string que almacena las palabras
	vector<string> palabras;
	//Hago un push_back con las palabras hardcodeadas
	palabras.push_back("mandarina");
	palabras.push_back("cascos");
	palabras.push_back("examen");
	//hago un srand para incializar los numeros aleatorios
	srand(time(NULL));

	short palabraRandom;//esta variable alamcenara el random
	short aciertos = 0;//esta almacena el numero de aciertos de la persona
	short errores = 0;//esta almacena el numero de fallos de la persona
	short palabrasRestantes = 3;//esta se encarga de que cantidad hacer el random
	short intentos;
	while (aciertos != 2)//while que no se saldra del bucle hasta que haga dos aciertos
	{
		palabraRandom = rand() % palabrasRestantes;//random que dependiendo de las palabras que haya es mas o menos grande y la almaceno en palabraRandom
		cout << palabras[palabraRandom] << endl;//muestra la palabra random
		cout << endl;

		vector<char> palabraNo;//este vector conendra las letras del usuario y los espacios vacios (_)
		for (int i = 0; i < palabras[palabraRandom].size(); i++)//un bucle for que llenara el vector anterior de '_'
		{
			palabraNo.push_back('_');
			cout << palabraNo[i];
		}
		cout << endl;
		intentos = palabraNo.size();//igualo la variable intentos con el tamaño de la palabra guardada

		while (intentos != 0)//no se saldra del bucle hasta que los intentos sean 0
		{
			cout << endl;
			cout << "Tienes " << intentos << " intentos"; //muestro los intentos
			cout << endl;
			intentos--;
			char letra;//variable que el usuario pondra la letra que quiera
			cout << "Pon una letra: ";
			cin >> letra;//escribe el usuario la letra
			for (int i = 0; i < palabraNo.size(); i++) //bucle que saldra cuando i sea igual a las letras de la palabra random
			{
				while (letra == palabraNo[i])//no saldra hasta que pongo una letra diferente
				{
					for (int i = 0; i < palabraNo.size(); i++)
					{
						cout << palabraNo[i];
					}
					cout << "Esta letra ya la has puesto, pon otra: ";// le muestro que ya lo ha puesto
					cin >> letra; // escribe el usuario la letra
				}
			}
			cout << endl;
			short acertado = 0;//variable que almacena las letras acertadas
			for (int i = 0; i < palabraNo.size(); i++) //bucle que saldra cuando i sea igual a las letras de la palabra random
			{
				if (letra == palabras[palabraRandom][i])//en caso de que la letra coincida con alguna letra la pondra en esa posicion
				{
					palabraNo[i] = letra;//lo pone en la posicion que son iguales
				}
				cout << palabraNo[i];//muestra la palabra con las letras que ha acertado
				if (palabraNo[i] != '_' )//en todas la posiciones que no haya un espacio vacio entrara
				{
					acertado++;//suma que ha acertado una letra
					if (acertado == palabraNo.size())//en caso que la suma de acertado sea igual al tamaño de la palabra
					{
						cout << endl;
						cout << "Has acertado la palabra" << endl;//muestro que lo ha acertado
						i = palabraNo.size(); //igualo la i al tamaño de la palabra para salir del for
						intentos = 0;// igualo los intentos a 0 para que se salga del while y muestre la siguiente palabra
						palabras.erase(palabras.begin() + palabraRandom); //borro la palabra para que no salga en el random
						aciertos++;//sumo que ha acertado una palabra
						palabrasRestantes--;//le resto del 3 al 2 para que haga un random entre el 0 y 1
					}
					else if (intentos == 0) //en caso que los intentos sean 0
					{
						errores++;//le suma una palabra fallada
						i = palabraNo.size();//igualo la i al tamaño de la palabra para salir del for
						cout << endl;
						cout << "Has fallado la palabra, era: " << palabras[palabraRandom] << endl; // muestro la palabra que ha fallado
						palabras.erase(palabras.begin() + palabraRandom); //borro la palabra para que no salga en el random
						palabrasRestantes--;
						if (errores == 2)//si hay dos palabras falladas
						{
							i = palabraNo.size();//igualo la i al tamaño de la palabra para salir del for
							intentos = 0; //igualo los intentos a 0 para que salgo del while y muestre la siguiente palabra
							aciertos = 2;
						}
						
					}
				}
			}
		}
	}
	if (errores == 2)//si hay dos errores
	{
		cout << "Game Over!!!" << endl;//le muestro que ha perdido
		cout << "Has hecho 2 errores" << endl;
	}
	else if (errores == 1)//si hay un error
	{
		cout << "Has ganado, pero mejorable" << endl;//le muestro que ha ganado 
		cout << "Has acertado dos, pero has fallado 1" << endl;
	}
	else if (errores == 0)//cuando no hay errores
	{
		cout << "Has ganado, sin fallar ninguna FELICIDADES!!!" << endl; //le muestro que ha ganado
	}
}