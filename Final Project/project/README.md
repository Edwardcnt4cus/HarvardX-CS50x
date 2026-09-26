# 📚 Book Store

#### Video Demo:  <https://youtu.be/edu12aWUlXI>

---

#### Description:
It is a full-stack **Flask web application** designed to simulate a complete online bookstore. Users can browse books, manage a shopping cart, place orders, and experience a simulated payment workflow. Administrators have full control over book listings and can monitor user orders through a dedicated admin dashboard.

This project integrates the knowledge acquired in CS50, including **backend development, database design, user authentication, session management, and responsive frontend design**. By building this project, I aimed to combine multiple CS50 concepts into a coherent, practical web application that simulates a real-world e-commerce environment.

---

## Features

### 👤 User Authentication
- Secure registration and login system
- Password hashing using **Werkzeug** for security
- Session-based authentication
- Role-based access control (admin and customer)

### 📖 Book Management
- Admins can add, edit, and delete books
- Each book includes title, author, price, description, and image
- Categorized display for easy browsing

### 🛒 Shopping Cart
- Add/remove books
- Update quantities dynamically
- Cart persists across user sessions

### 📦 Order Processing
- Users can place orders
- Order history is available per user
- Orders are stored in the database

### 💳 Payment Simulation
- Simulated payment workflow (test mode only)
- No real payments or API keys required
- Application works without external services

### 📱 Responsive Design
- Mobile-friendly layout
- Styled using **Bootstrap** and custom CSS

---

## Technologies Used

Python 3.10+, Flask, SQLite, SQLAlchemy, Flask-WTF, HTML, CSS, JavaScript, Bootstrap, Jinja2

---

## Project Structure

```text
BookStore/
├── app/
│   ├── __init__.py       # Initializes Flask app and registers blueprints
│   ├── models.py         # SQLAlchemy models
│   ├── routes.py         # Main route handlers
│   ├── forms.py          # Flask-WTF form classes
│   ├── auth.py           # Authentication routes and logic
│   ├── admin.py          # Admin dashboard and controls
│   ├── templates/
│   │   ├── base.html
│   │   ├── home.html
│   │   ├── login.html
│   │   ├── signup.html
│   │   ├── cart.html
│   │   ├── orders.html
│   │   └── ...
│   └── static/
│       ├── css/
│       │   ├── style.css
│       │   └── bootstrap.min.css
│       ├── js/
│       │   ├── script.js
│       │   └── jquery.js
│       └── images/
│           └── logo.png
├── instance/
│   └── config.py
├── media/
├── migrations/
├── .venv/
├── requirements.txt
├── README.md
└── main.py
```

## How to Run the Application

### Prerequisites
- Python 3.10+
- pip

### Setup Instructions
```bash

# Clone the repository
git clone https://github.com/Edwardcnt4cus/BookStore.git
cd BookStore

# Create virtual environment
python3 -m venv .venv
source .venv/bin/activate       # Linux/Mac
.venv\Scripts\activate          # Windows

# Install dependencies
pip install -r requirements.txt

# Set up the database
flask db init
flask db migrate
flask db upgrade

# Run the application
flask run

# Acess the application
Visit http://127.0.0.1:5000/
 in your web browser.

# Key Files
-`app/models.py` — Defines database models for users, books, carts, and orders

-`app/routes.py` — Core application routes

-`app/auth.py` — Authentication logic and session management

-`app/admin.py` — Admin dashboard and controls

-`app/forms.py` — Flask-WTF forms for input validation

-`templates/` — HTML templates for rendering pages

-`static/` — CSS, JavaScript, and images

-`run.py` — Entry point to start the Flask application

## CS50 Compliance

This project meets the CS50 final project requirements:

1. **Complexity:** Implements advanced features including user authentication, book management, shopping cart functionality, order processing, and simulated payment workflow.
2. **Originality:** Designed and developed entirely from scratch with no external boilerplate code.
3. **Documentation:** Comprehensive README.md with setup instructions, project structure, feature explanations, and challenges faced.
4. **Presentation:** Includes a recorded video demo explaining the project, accessible [here](https://youtu.be/edu12aWUlXI).


# License
This project is licensed under the MIT License.

## Contributing

Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. **Fork the repository**
2. **Create a new feature branch**
```bash
git checkout -b feature/your-feature
3. **Make your changes and commit**
```bash
git commit -m "Add some feature"
4. **Push your branch to your fork**
```bash
git push origin feature/your-feature
5. **Open a pull request**

Please make sure your code follows the existing project structure and styling for consistency.

# Challenges & Learning
During development, I faced several challenges:

- **Designing** a relational database to handle users, books, carts, and orders efficiently

- **Implementing** secure authentication with hashed passwords and session management

- **Handling dynamic** cart and order logic without introducing duplication or errors

- **Structuring** the Flask application using blueprints to separate authentication, admin, and main routes

- **Ensuring** the application is responsive and visually appealing across devices

This project enhanced my skills in full-stack web development, problem-solving, and application design, while applying CS50 concepts in a real-world context. It also taught me how to organize a multi-module Flask project efficiently, handle user sessions securely, and simulate real-world e-commerce workflows.



## Contact
Email: thukhanaing533@gmail.com

GitHub: https://github.com/Edwardcnt4cus

