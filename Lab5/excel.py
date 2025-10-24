import sys
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QLabel, QTableWidget, QFileDialog
)
from PyQt5.QtCore import Qt

class ExcelGrid(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Excel Grid - DSA")  # Window title
        self.resize(1920, 1200)  # Set window size (width x height)
        self.initUI()  # Initialize UI elements

    def initUI(self):
        # Main vertical layout for the entire window
        layout = QVBoxLayout()

        # Label to show currently selected cell address (like A1, B3, etc.)
        self.address_label = QLabel("Selected cell: None")
        layout.addWidget(self.address_label)

        # Create a 10x10 table (like a small Excel grid)
        self.table = QTableWidget(10, 10)

        # Set column headers (A, B, C, ...)
        self.table.setHorizontalHeaderLabels([chr(65 + i) for i in range(10)])

        # Set row headers (1, 2, 3, ...)
        self.table.setVerticalHeaderLabels([str(i + 1) for i in range(10)])

        layout.addWidget(self.table)  # Add the table to the main layout

        # Create a horizontal layout for buttons
        btn_layout = QHBoxLayout()

        # Create "Clear All" and "Save" buttons
        clear_btn = QPushButton("Clear All")
        save_btn = QPushButton("Save")

        # Connect button clicks to respective methods
        clear_btn.clicked.connect(self.clear_all)
        save_btn.clicked.connect(self.save_to_file)

        # Add buttons to the button layout
        btn_layout.addWidget(clear_btn)
        btn_layout.addWidget(save_btn)

        # Add the horizontal button layout to the main vertical layout
        layout.addLayout(btn_layout)

        # Update address label whenever user changes the selected cell
        self.table.currentCellChanged.connect(self.update_address)

        # Set the complete layout for the window
        self.setLayout(layout)

    def update_address(self, row, col, *_):
        """Updates the address label when the user selects a new cell."""
        if row >= 0 and col >= 0:
            # Convert column index (0 → A, 1 → B, etc.)
            col_letter = chr(65 + col)
            # Display selected cell like "A1", "C5", etc.
            self.address_label.setText(f"Selected cell: {col_letter}{row + 1}")

    def clear_all(self):
        """Clears all the cell contents (but keeps table structure)."""
        self.table.clearContents()

    def save_to_file(self):
        """Saves the table data into a CSV file."""
        # Open a file dialog to select where to save the file
        path, _ = QFileDialog.getSaveFileName(self, "Save File", "", "CSV Files (*.csv)")
        if not path:  # If user cancels, stop the function
            return

        # Open the selected file for writing
        with open(path, "w") as file:
            # Loop through each row
            for r in range(self.table.rowCount()):
                row_data = []
                # Loop through each column in the current row
                for c in range(self.table.columnCount()):
                    item = self.table.item(r, c)
                    # Get cell text if cell is not empty
                    row_data.append(item.text() if item else "")
                # Write row as comma-separated values
                file.write(",".join(row_data) + "\n")


# Main program entry point
if __name__ == "__main__":
    app = QApplication(sys.argv)  # Create application instance
    window = ExcelGrid()  # Create the main window
    window.show()  # Display the window
    sys.exit(app.exec_())  # Start the application event loop
