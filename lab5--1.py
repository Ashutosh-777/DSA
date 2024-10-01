import sys
from PyQt6.QtWidgets import QApplication, QWidget, QLabel, QComboBox, QVBoxLayout, QPushButton, QMessageBox

class FriendDropdown(QWidget):
    def __init__(self, friend_list, button_text, parent=None):
        super().__init__(parent)

        self.friend_list = friend_list

        self.label = QLabel(f"Select Friend:")
        self.dropdown = QComboBox()
        self.dropdown.addItem("Select Friend")
        self.dropdown.addItems(self.friend_list)

        self.print_button = QPushButton(button_text)
        self.print_button.clicked.connect(self.print_friends)

        layout = QVBoxLayout(self)
        layout.addWidget(self.label)
        layout.addWidget(self.dropdown)
        layout.addWidget(self.print_button)

    def print_friends(self):
        selected_friend = self.dropdown.currentText()
        if selected_friend != "Select Friend":
            QMessageBox.information(self, self.print_button.text(), f"Selected Friend: {selected_friend}")
        else:
            QMessageBox.warning(self, self.print_button.text(), "No friend selected. Please choose a friend.")

class MainApp(QWidget):
    def __init__(self):
        super().__init__()

        friend_list = ["Friend 1", "Friend 2", "Friend 3", "Friend 4", "Friend 5", "Friend 6"]

        self.friend_dropdown1 = FriendDropdown(friend_list, "Print Friends")
        self.friend_dropdown2 = FriendDropdown(friend_list, "Mutual Friends")

        layout = QVBoxLayout(self)
        layout.addWidget(self.friend_dropdown1)
        layout.addWidget(self.friend_dropdown2)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_app = MainApp()
    main_app.show()
    sys.exit(app.exec())
