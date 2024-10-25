#include <Arduino.h>

//* ----------------------------------------------------------------------------------------------------------------
//* ---------------------------------------   DOCUMENTACAO OFICIAL   -----------------------------------------------
//* ----------------------------------------------------------------------------------------------------------------
//* ARDUINO:
//? https://www.arduino.cc/reference/en/
//* PlatformIO:
//? https://docs.platformio.org/en/latest/
//* C++:
//? https://cplusplus.com/doc/tutorial/

//* ----------------------------------------------------------------------------------------------------------------
//* -----------------------------------------   CRIAÇÃO DE ARRAYS   ------------------------------------------------
//* ----------------------------------------------------------------------------------------------------------------
//? All of the methods below are valid ways to create (declare) an array.
// Declare an array of a given length without initializing the values:
int myInts[6];
// Declare an array without explicitely choosing a size (the compiler
// counts the elements and creates an array of the appropriate size):
int myPins[] = {2, 4, 8, 3, 6, 4};
// Declare an array of a given length and initialize its values:
int mySensVals[5] = {2, 4, -8, 3, 2};
// When declaring an array of type char, you'll need to make it longer
// by one element to hold the required the null termination character:
char message[6] = "hello";

//* ----------------------------------------------------------------------------------------------------------------
//* ----------------------------------------   CRIAÇÃO DE STRUCTS   ------------------------------------------------
//* ----------------------------------------------------------------------------------------------------------------
//? A data structure is a group of data elements grouped together under one name.These data elements, known as members, can have different types and different lengths.Data structures can be declared in C++ using the following syntax:

//* ----------------------------
//* EXEMPLO - MyStruct:
//* ----------------------------
struct product
{
    String algum_texto;
    int algum_numero_inteiro;
    double algum_numero_double;
    float algum_numero_float;
    bool algum_booleano;
    int algum_array_int[5];
    // declarar outros tipos restantes (caso precise e eu acho q n vai kkk)...
    // bool
    // boolean
    // byte
    // char
    // double
    // float
    // int
    // long
    // short
    // size_t
    // String
    // unsigned
    // char
    // nsigned
    // int
    // unsigned
    // long
    // void
    // word
} my_struct_instance_name;

//* Exemplo para acessar e atribuir valores:
void exemplo_struct()
{
    //* Atribuindo valores:
    my_struct_instance_name.algum_texto = "texto";
    my_struct_instance_name.algum_numero_inteiro = 0;
    my_struct_instance_name.algum_numero_double = 0.0;
    my_struct_instance_name.algum_numero_float = 0.0;
    my_struct_instance_name.algum_booleano = true;
    my_struct_instance_name.algum_array_int[0] = 0;
}

//* ----------------------------------------------------------------------------------------------------------------
//* ----------------------------------------   CRIAÇÃO DE CLASSES   ------------------------------------------------
//* ----------------------------------------------------------------------------------------------------------------

//* ----------------------------
//* EXEMPLO - MyClass:
//* ----------------------------
class MyClass
{ // The class

public:                        // Access specifier
    int myNum = 0;             // Attribute (int variable)
    String myString = "teste"; // Attribute (string variable)
    MyClass(int a, int b);     // Constructor declaration

protected:      // Access specifier
    int myNum2; // Attribute (int variable)

private:        // Access specifier
    int myNum3; // Attribute (int variable)
};

// Constructor definition.
MyClass::MyClass(int a, int b)
{
    myNum = a;
    myNum2 = b;
}

//* ----------------------------
//* EXEMPLO - MyOtherClass:
//* ----------------------------
class MyOtherClass
{                              // The class
public:                        // Access specifier
    int myNum = 0;             // Attribute (int variable)
    String myString = "teste"; // Attribute (string variable)
    MyOtherClass(int a, int b) // Constructor declaration
    {
        myNum = a;
        myNum2 = b;
        myNum3 = a + b;
    };
    void myMethod(){
        // code here.
    };

protected:      // Access specifier
    int myNum2; // Attribute (int variable)

private:        // Access specifier
    int myNum3; // Attribute (int variable)
};

//* ----------------------------------------------------------------------------------------------------------------
//* ----------------------------------------   SEPARANDO ARQUIVOS   ------------------------------------------------
//* ----------------------------------------------------------------------------------------------------------------

//* ----------------------------
//* Para separar o código em múltiplos arquivos, devemos:
//* ----------------------------
//? 1) Criar um arquivo nome_arquivo.h
//? 2) Utilizar o código abaixo no arquivo nome_arquivo.h
//? 3) Incluir o código do arquivo nome_arquivo.h no arquivo principal (main.cpp).

//* ----------------------------
//* EXEMPLO - nome_arquivo.h:
//* ----------------------------
#ifndef HEADER_INCLUDED_
#define HEADER_INCLUDED_

//? seu código aqui

#endif

//* ----------------------------
//* EXEMPLO - main.cpp:
//* ----------------------------
//? #include <Arduino.h>
//? #include "nome_arquivo.h"
//?
//? void setup() {
//? etc...
//? }