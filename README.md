# 🛒 SuperMart-Console

**SuperMart Console** is a C++ based console application that simulates a shopping system. The application allows administrators to manage products and buyers to purchase items, generating receipts based on their orders.

## ✨ Features

- **🔑 Administrator Menu:**
  - ➕ Add new products.
  - ✏️ Edit existing products.
  - ❌ Delete products.
  - 📋 View a list of all available products.

- **🛍️ Buyer Menu:**
  - 🔍 Browse available products.
  - 🛒 Purchase products and generate a receipt.

## 🛠️ How It Works

### 👨‍💼 Administrator
- 🔐 Log in with credentials to access the administrator menu.
- ➕ Add, ✏️ edit, or ❌ delete products in the inventory.
- 📂 The product information is stored in a text file (`database.txt`).

### 🛒 Buyer
- 🔍 Browse the available products.
- 📝 Select and purchase products by entering the product code and quantity.
- 🧾 The application generates a receipt showing the total amount, including discounts.

## 🚀 Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/patilvikas580/supermart-console.git
    ```
2. **Navigate to the project directory:**
    ```bash
    cd supermart-console
    ```
3. **Compile the source code:**
    ```bash
    g++ -o supermart shopping.cpp
    ```
4. **Run the application:**
    ```bash
    ./supermart
    ```

## 💡 Usage

- Run the program and select either "🔑 Administrator" or "🛍️ Buyer".
- Follow the prompts to either manage products or purchase items.
- Product data is stored in `database.txt`.

## 📁 File Structure

- `shopping.cpp`: The main source code file containing the class definition and function implementations.
- `database.txt`: The text file where product information is stored.

## 🤝 Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
