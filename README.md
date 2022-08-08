# UCF Narcissus Hackpack

- PDF: [Echo.pdf](https://github.com/UCF-Narcissus/HackPack/releases/download/v1.0/Echo.pdf)

## Style
- use only the `#define`s and `typedef`s in the [template](https://github.com/ucf-programming-team/hackpack-cpp/blob/master/content/contest/template.cpp)
- run the formatter on any code you commit (`make format`)
    - you may need to install clang-format (`sudo apt install clang-format-10`)
- name files in upper camel case

## Building PDF
The three dependencies for making the PDF are LaTeX, Python, and Make.
To build the hackpack PDF, go to the base directory and run `make kactl`.

## Snippets
![snippet](https://user-images.githubusercontent.com/30928035/93427043-1f731600-f88b-11ea-8b77-64aa6537b70e.gif)

To use the snippets:
- Download [cpp.json](https://github.com/ucf-programming-team/hackpack-cpp/releases/download/latest/cpp.json)
- Find the C++ snippet file in VSCode (File->Preferences->User Snippets->cpp.json) 
- Copy and paste the `cpp.json` file into VSCode

To make/update the snippets, you just need to run `make snippets`, 
and it will assemble all of the snippets for you in `snippets/cpp.json` or `snippets/java.json`.

VSCode's soft tabs should match whatever style of tabs you're using. So, if you were using 2 spaces, all of the code that gets imported via snippet should also be in 2 spaces.
