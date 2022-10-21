
<h1 align="center">
	🔄 push_swap
</h1>

### 🗝️ Original in [**Russian**](https://github.com/AYglazk0v/push_swap/blob/master/README.md)

## 💡 About the project:

> _This project will force you to sort the data on the stack, with a limited set of instructions, using as few actions as possible. To succeed, you will have to manipulate different types of algorithms and choose the most appropriate solution (out of many) for an optimized sorting of the data._

	The Push swap project is a very simple algorithm project: the data must be sorted.
	You have a set of integer values, 2 stacks and a set of instructions for
	to handle both stacks.
	Your goal? To write a C program called push_swap that calculates and
	outputs to standard output the smallest program made up of
	Push swap language instructions that sorts the integers received as
	arguments.

More details about the assignment can be found in  [**subject**](https://github.com/MKKurbandibirov/push_swap/blob/master/Subject.pdf).


## 🛠️ Usage:

### Requirements

The function is written in C and therefore needs the `gcc` compiler and some standard C libraries to execute it.

### Instructions

**1. Build the project**

To build a project, simply clone the repository and run the command there:

```shell
$ make
```

**2. Using the program**

In order to execute the program you must:

```C
$ ./push_swap $ARG
```

where `$ARG` is a space-separated list of integers, e.g. `ARG="1 5 2 4 3"`


### Activities

**PUSH:**
Take the first element at the top of one stack and put it on top of the other; do nothing if the original stack is empty.

* **`pa`** - the top element _stack b_ goes to the top of _stack a_.
* **`pb`** - the top element _stack a_ passes to the top element _stack b_.

**SWAP:**
Swap the first 2 elements at the top of the stack; do nothing if there is only one or none.

* **`sa`** - swap  _stack a_.
* **`sb`** - swap  _stack b_.
* **`ss`** - `sa` and `sb` per operation.

**ROTATE:**
Shift up all elements of the stack by one; the first element becomes the last one.

* **`ra`** - rotate stack a.
* **`rb`** - rotate stack b.
* **`rr`** - `ra` and `rb` per operation.

**REVERSE ROTATE:**
Shift down all elements of the stack by one; the last element becomes the first.

* **`rra`** - reverse rotate stack a.
* **`rrb`** - reverse rotate stack b.
* **`rrr`** - `rra` and `rrb` per operation.

 ## 📋 Testing:

To check the project, you can use the [checker_linux](https://github.com/AYglazk0v/push_swap/blob/master/checker_linux), or take advantage of:

* [SimonCROS/push_swap_complexity_tester](https://github.com/SimonCROS/push_swap_tester)
* [laisarena/complete_push_swap_tester](https://github.com/laisarena/push_swap_tester)

You can also use the visualizer:

* [o-reo/push_swap_visualizaer](https://github.com/o-reo/push_swap_visualizer)
