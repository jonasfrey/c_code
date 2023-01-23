
// c file 
#include <stdio.h>
#include <string.h>

typedef struct {
   int n_id;
   char s_name[100]; 
} O_person;
int main() {
   // in most high level programming languages a copy of an object can so easy be created

   // ```javascript
   // let o_1 = {s_name:"test"};
   // let o_2 = o_2;// this wont copy o_1 into o_2, but only copy the reference to o_1 into o_2
   // o_1.s_name = "hans";// every manipulation done on o_1 will also be done on o_2 , because o_2 is only a different name / a reference to o_1
   // console.log(o_1.s_name);//"hans"
   // console.log(o_2.s_name);//"hans"
   // o_2.s_name = "rudolf"
   // console.log(o_1.s_name);//"rudolf"
   // console.log(o_2.s_name);//"rudolf"
   // ```

   O_person o_person_1 = { 1, "test" };
   O_person o_person_2 = o_person_1; // this will copy the object!

   strcpy(o_person_1.s_name, "Hans");

   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Hans"
   printf("o_person_2.s_name: %s\n", o_person_2.s_name);//"test"

   strcpy(o_person_2.s_name, "Rudolf");

   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Hans"
   printf("o_person_2.s_name: %s\n", o_person_2.s_name);//"Rudolf"

   // as you can see in c-language an object can be copied by just assigning one instance name to another


   // now to references

   O_person * n_ptr_o_person = &o_person_1;// now we will copy the index / address into a variable 

   O_person o_person_3 = *n_ptr_o_person; // now we will read out the value at that index /address "dereference" it
                                          // this will also copy the object
   strcpy(o_person_1.s_name, "Jasmin");

   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Jasmin"
   printf("o_person_2.s_name: %s\n", o_person_2.s_name);//"Rudolf"  
   printf("o_person_3.s_name: %s\n", o_person_3.s_name);//"Hans"


   // to be able to have the real reference we need to handle the index / address / reference 

   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Jasmin"
   printf("n_ptr_o_person->s_name: %s\n", n_ptr_o_person->s_name);//note that now we are using arrow notation (o->prop) instead of dot notation (o.prop) "Jasmin"
   printf("(*n_ptr_o_person).s_name: %s\n", (*n_ptr_o_person).s_name);//we can also de-reference and then read the property
   
   // if we want to change the original object content via the reference 

   strcpy(n_ptr_o_person->s_name, "Reinhard");  
   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Reinhard"

   strcpy((*n_ptr_o_person).s_name, "Alberta");
   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Alberta"


   O_person o = (*n_ptr_o_person); // this will create a copy ... 
   strcpy(o.s_name, "Margrit"); // this wont change the content of o_person_1
   printf("o_person_1.s_name: %s\n", o_person_1.s_name);//"Alberta"
   
   
}
