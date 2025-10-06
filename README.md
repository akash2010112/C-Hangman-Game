# C Hangman Game

This is a simple Hangman game implemented in C. It was developed as part of a series of personal projects to learn the fundamentals of the C language. The player must guess a secret word letter by letter before running out of attempts.

## Features

- Console-based game.
- Random word selection from a predefined list.
- ASCII representation of the hangman.
- Checks for repeated letters.
- Allows multiple rounds without restarting the program.

## Compilation

You can compile the program using `gcc`:

```c
gcc -o hangman hangman.c
```

## Running the Game

Once compiled, run the program:

```c
./hangman
```

## Example Usage

```c
Word: _ _ _ _ _ _
Tries: 0/6
Letters used:
Enter a letter: e
Good guess!

Word: _ e _ _ _ _
Tries: 0/6
Letters used: e
...
```

## Possible Future Improvements

- Load words from an external file.
- Track player wins and losses.
- Add support for other languages.

## Contributing

This is a personal project, but suggestions or improvements are welcome! You can submit a pull request or open an issue to propose changes or report bugs.

## License

[MIT](https://choosealicense.com/licenses/mit/)
