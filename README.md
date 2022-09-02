<h1 align="center">
	🧰 Get Next Line
</h1>

<p align="center">
	<b><i>FUNCTION TO GET LINE FROM FILE DESCRIPTOR</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/aabduvak/GNL?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/aabduvak/GNL?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/aabduvak/GNL?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/aabduvak/GNL?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/aabduvak/GNL?color=green" />
</p>

<h3 align="center">
	<a href="#-about-the-project">About</a>
	<span> · </span>
	<a href="#getting-started">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The goal of this project is to create the function get_next_line.c which, when called in a loop, will then allow the available text in the file descriptor to be read one line at a time until the end of the file. The program must compile with the flag-D BUFFER_SIZE=xx which will be used as the buffer size for the read calls in get_next_line.

### What is GNL?
Get Next Line is an individual project at [42](https://www.42istanbul.com.tr/) that requires us to create a function similar to the getline from CPP and fgets from C. This function allows a file to be read line after line if called in a loop.

### Application flow
Click [here](https://excalidraw.com/#json=kbWSFRGd3J4Zdg45Q_nHs,Eyv_Lr8kBJ2EkW0xhXCnPw) for the interactive link.

#### Objectives
- Unix logic

#### Skills
- Rigor
- Unix
- Algorithms & AI

#### My grade
<img src="./images/grade.png" width="150" height="150"/>

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/abdulazizabduvakhobov/GNL && cd GNL/
# Create a main file
touch main.c
```

```c
/*
** Example of a main, change "myfile.txt"
** to a file you want to read
*/
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(void)
{
	char	*temp;
	int	fd;
	fd = open("myfile.txt", O_RDONLY);
	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}
```

```bash
# Compile the files, example:
gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c
# Execute your program
./a.out
# Well done!
```

## Functions table reference
The functions present in the utils are from the [Libft](https://github.com/abdulazizabduvakhobov/Libft) with some code optimizations.

<table>
    <thead>
        <tr>
            <th colspan=3><h4>GNL Functions</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=get_next_line.c>ft_clear_backup</a></td>
            <td>Free the memory and sets to NULL a pointer of type **char.</td>
        </tr>
        <tr>
        <tr>
            <td><a href=get_next_line.c>ft_update</a></td>
            <td>Joins all slices of backup and returns it</td>
        </tr>
        </tr>
            <td><a href=get_next_line.c>ft_init_string</a></td>
            <td>Creates new string and return the result string</td>
        </tr>
        <tr>
            <td><a href=get_next_line.c>get_next_line</a></td>
            <td>Reads a line from a file descriptor.</td>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Libft Functions</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strlen</a></td>
            <td>Computes the length of the string but not including the terminating null character.</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_substr</a></td>
            <td>Creates new string from start parameter to length</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strchr</a></td>
            <td>Returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'.</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strjoin</a></td>
            <td>Returns a new string, which is the result of the concatenation of 's1' and 's2'.</td>
        </tr>
    </tbody>
</table>

## Updating

The project is regularly updated with bug fixes and code optimization.

---

## 📋 Testing

You can use any of this third party testers to test the project

* [Tripouille/libfTester](https://github.com/Tripouille/gnlTester)
