#include <Python.h>

/**
  * print_python_list_info - prints basic info about python lists
  * @p: A python Object list 
  */

void print_python_list_info(Pyobject *p)
{
	int size, alloc, i;
	Pyobject *obj;

	size = Py_SIZE(p);
	alloc = ((PyListobject *)p)->allocated;

	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);

	for (i = 0; i < size; i++)
	{
		printf("Element %d: ", i);
		obj = Pylist_GetItem(p, i);
		printf("%s\n", Py_Type(obj)->tp_name);
	}
}

