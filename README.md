# Console Voting Application (C++)
A lightweight, menu-driven command-line program implemented in C++ to simulate a secure voting process for five predefined political parties. Key features include:

Voting Engine: Allows users to cast votes for any of the five parties via intuitive console menus, with real-time vote tallies.

Admin Authentication: Implements a simple username/password check to restrict access to administrative functions.

Voting Control: Enables the authenticated administrator to pause, resume, or terminate the voting session at any point.

Result Publication: Upon completion, the admin can generate a summary report that automatically detects and handles both a clear-win scenario (highest vote count) and tie situations, displaying tied parties when a draw occurs.

The application emphasizes modular design, using classes for authentication, voting logic, and result computation, and ensures robust input validation and error handling throughout.
