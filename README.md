# Push Swap

[Subject](https://github.com/MKKurbandibirov/Numbers_convert-aka-C_Rush_02-/files/7971794/en.subject.1.pdf)

## Mandatory part

  The task is to receive a sequence of elements as input and put them on the stack ```stack a``` (after checking for duplicates and literals) sort the sequence using an additional ```stack b``` and only the following operations:

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.

* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.

* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

The program should output a sequence of commands with which you can sort the ```stack a```

### Examples:

* Error validation:

![image](https://user-images.githubusercontent.com/74917681/151823654-a5a6321c-efaf-439a-8550-9bccf278584d.png)
---

* Standart work:

![image](https://user-images.githubusercontent.com/74917681/151823824-b22b8d1f-edb5-4a5f-9b98-de096c45b50d.png)
---

## Bonus part

In this part should write your own ```checker``` programm to check your ```push_swap``` and write in terminal "OK" if stack is sorted or "KO" if it is not.

### Examples:
* Error validation the same as in the mandatory part and checking sorting commands
* Bonus work:

![image](https://user-images.githubusercontent.com/74917681/151827211-1818e580-b57d-44a3-bb5f-656893ab201c.png)
---

## Testing

if you want to test your ```push_swap``` go to ```ps_test``` directory and follow the instructions in ```Readme.md``` there
