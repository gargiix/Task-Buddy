# Task Buddy

A C++ command-line task manager that keeps your most urgent work on top and nudges you about what's still pending.

## Features
- Add tasks with a priority (1 = most urgent)
- Mark tasks as complete
- View pending tasks by urgency, using a priority queue (heap)
- Tasks are saved to a file and reloaded on startup
- Reminder mode: every N minutes, lists pending tasks with a nudge about the cost of delaying them
- Input validation, so bad input doesn't crash the program

## Tech
C++, STL (`vector`, `priority_queue`), file I/O (`fstream`), `<thread>` / `<chrono>`

## How to run
    g++ main.cpp -o main
    .\main

## What I learned
- Building a custom comparator for `priority_queue`
- Reading and writing files in C++
- Handling invalid user input with `cin`

## Roadmap
- REST API backend
- AI-generated reminder messages
- Desktop companion with break timers