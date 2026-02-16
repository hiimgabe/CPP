# CPP01
This module aims to get acquainted with Memory allocation, pointers to members, references and switch statement. see [subject](en.subject.pdf).

### Exercise00: BraiiiiiiinnnzzzZ

Exercise 00 involves implementing a `Zombie` class with a private attribute `name`. The class includes a member function `announce()` that prints the zombie's name followed by "BraiiiiiiinnnzzzZ...". Additionally, two functions are implemented:
- `Zombie* newZombie(std::string name)`: Creates a new zombie on the heap with the given name and returns a pointer to it. This allows the zombie to persist beyond the function scope, requiring manual deletion by the caller to prevent memory leaks.
- `void randomChump(std::string name)`: Creates a zombie on the stack with the given name and announces it. The zombie is automatically destroyed when the function returns, making it suitable for temporary zombies.

The exercise prompts consideration of whether it's better to allocate zombies on the stack or heap. Stack allocation (randomChump) is appropriate for short-lived objects that don't need to persist beyond their scope, while heap allocation (newZombie) is necessary when objects need to outlive the function that creates them. The destructor of the `Zombie` class prints a message with the name of the zombie for debugging purposes, helping track when zombies are properly destroyed.

### Exercise01: Moar brainz!

Exercise 01 introduces a function `zombieHorde(int N, std::string name)` that allocates N `Zombie` objects in a single allocation using `new Zombie[N]`. The function returns a pointer to the first zombie. This demonstrates array allocation versus single object allocation, emphasizing that arrays must be deallocated with `delete[]` to properly destroy all objects and prevent memory leaks.

### Exercise02: HI THIS IS BRAIN

Exercise 02 creates a string variable alongside a pointer and reference to it, then prints their memory addresses and values.
- Memory addresses of the variable, pointer, and reference are identical
- Values can be accessed through the variable, dereferenced pointer, and reference
- References must be initialized and cannot be null or reassigned

The goal is to demystify references by showing they're another syntax for address manipulation.

### Exercise03: Unnecessary violence

Exercise 03 implements a `Weapon` class and two human classes that attack with weapons.
- `HumanA`: takes weapon reference in constructor, always armed
- `HumanB`: uses weapon pointer, may not always have a weapon
- References guarantee object existence and cannot be reassigned
- Pointers allow optional/nullable objects

This demonstrates when to use references (mandatory, unchanging) versus pointers (optional, reassignable).

### Exercise04: Sed is for losers

Exercise 04 creates a program that takes a filename and two strings (s1 and s2), then replaces all occurrences of s1 with s2 in a new file.
- Opens the file and reads its content
- Replaces every occurrence of s1 with s2
- Writes the result to `<filename>.replace`
- C file manipulation functions (`fopen`, `fread`, etc.) are forbidden

This demonstrates file stream manipulation using C++ classes (ifstream/ofstream) instead of C functions.

### Exercise05: Harl 2.0

Exercise 05 implements a `Harl` class with four complaint levels (debug, info, warning, error) and a `complain()` function that calls the appropriate level based on a string parameter.
- Uses pointers to member functions to map strings to methods
- Avoids if/else chains by using an array of function pointers
- Demonstrates the syntax `(this->*funcPtr)()`

This introduces pointers to member functions as an elegant alternative to conditional branching.

### Exercise06: Harl filter

Exercise 06 creates a program that takes a log level as a parameter and displays all messages from that level and above.
- Uses a switch statement to filter messages by severity
- Displays all levels at or above the specified threshold
- Falls through cases intentionally to show cascading levels
- Handles invalid levels with a default case

This introduces the switch statement and demonstrates fall-through behavior for hierarchical filtering.
