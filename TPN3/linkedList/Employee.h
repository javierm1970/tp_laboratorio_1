#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void muestraUnEmpleado(Employee* emp);
void muestraEmpleados(LinkedList* pArrayLinkedList);

int ordenaPorId(void* emp1, void* emp2);
int ordenaPorNombre(void* emp1, void* emp2);
int ordenaPorHorasTrabajadas(void* emp1 , void* emp2);
int ordenaPorSalario(void* emp1, void* emp2);

//void ll_sort2(LinkedList* pArrayLinkedList, int ord);






#endif // employee_H_INCLUDED
