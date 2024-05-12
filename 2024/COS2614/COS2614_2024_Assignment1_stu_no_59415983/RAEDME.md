# QUESTION2:
The provided code is a complete C++ console application that models an online store inventory system. Here's a breakdown of each component and its purpose, ensuring clarity on how the code functions and its design choices:

## Item Class
 * Purpose: Represents a generic item in the store.
 * Properties: Includes id, name, and price.
 * Methods:
	* Getters and Setters: For each property to encapsulate the data.
    * toString(): Returns a string representation of the item, useful for displaying item details in a user-friendly format.

## Supplier Class
 * Purpose: Represents a supplier providing items to the store.
 * Properties: Includes supplierId, name, and address.
 * Methods:
   * Getters and Setters: Manage supplier details securely.
   * toString(): Generates a string that summarizes the supplier's information, aiding in easy logging and display.

## StoreItem Class
 * Purpose: Extends the Item class by adding supplier information, representing items in the store that are linked to specific suppliers.
 * Properties: Inherits id, name, and price from Item and adds a supplier pointer.
 * Methods:
   * setSupplier(): Associates a Supplier object with the StoreItem. Uses std::unique_ptr for memory management, ensuring that the supplier object is automatically managed and deleted when no longer needed, preventing memory leaks.
   * getSupplierName(): Provides the name of the supplier or "Unknown" if no supplier is set, useful for situations where supplier details might be optional.
   * toString(bool includeSupplierDetails): Overloaded to optionally include supplier details in the item's string representation, offering flexibility in how much detail to display.

## Main Function
 * Purpose: Demonstrates the usage of the StoreItem and Supplier classes.
 * Process:
   * Creates an instance of StoreItem and Supplier.
   * Links the StoreItem with the Supplier.
   * Displays the item details with and without supplier information.
   * This function serves as a practical example of how the classes can be utilized in an application, showing the output directly to the console.

## Design Choices
 * Use of std::unique_ptr in StoreItem: Ensures that the memory allocated for the Supplier is properly managed. This smart pointer automatically handles the deletion of the supplier object, which is crucial in preventing memory leaks in applications dealing with dynamic memory allocation.
 * Standard C++ Libraries: The use of standard libraries like <iostream>, <string>, and <memory> ensures that the application is portable and does not rely on third-party libraries, making it more accessible and easier to compile on various platforms.

 * Explanation:
   * This structured approach not only adheres to object-oriented principles such as encapsulation and inheritance but also demonstrates good memory management practices. The application is designed to be modular, allowing for easy expansion or modification, such as adding more properties to items or suppliers, or introducing new functionalities like inventory management or supplier evaluations.