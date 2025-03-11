🚗 Binary Search Tree (BST) using Linked List - Vehicle Parking System 🚦
This program implements a Binary Search Tree (BST) using a linked list to manage a vehicle parking system. It allows users to add, view, update, and remove vehicle data efficiently. The system ensures proper validation for inputs and provides a structured menu-driven interface for easy navigation.

📋 Menu Options
Menu 1: Add Data
Add Data: Add a new vehicle entry to the system.

Auto Generate Vehicle Code:

Format: B [0-9][0-9][0-9][0-9] [A-Z][A-Z][A-Z] (e.g., B 1234 XYZ).

Input Vehicle Owner:

Must contain at least two words.

Must be between 5-20 characters.

Input Vehicle In Time:

Must be between 6-9.

Input Vehicle Type:

Options: Sedan, Truck, or Motorcycle.

Set Vehicle Status: Automatically set to IN.

Display All Data: Shows all vehicle entries in the BST.

Menu 2: View Data
View Data: View vehicle data using different tree traversal methods.

Pre-Order: Displays data in pre-order traversal.

In-Order: Displays data in sorted order.

Post-Order: Displays data in post-order traversal.

Menu 3: Update Data
Update Data: Update vehicle details when a vehicle leaves the parking lot.

Input Vehicle Code: Enter the vehicle code to search for the vehicle.

Check Found or Not: The system checks if the vehicle exists in the BST.

If Found:

Input Vehicle Out Time: Must be between 10-18.

Set Vehicle Status: Update the status to OUT.

Calculate Payment: Payment is calculated based on the vehicle type and duration:

Sedan: (OUT TIME - IN TIME) * 3000

Truck: (OUT TIME - IN TIME) * 4000

Motorcycle: (OUT TIME - IN TIME) * 2000

Display All Data: Shows all vehicle entries after updating.

Menu 4: Exit
Exit: Exits the program.

Pop-All Data: Removes all data from the BST before exiting.
