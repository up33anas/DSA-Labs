import sys
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QLabel, QTableWidget, QFileDialog
)
from PyQt5.QtCore import Qt

class ExcelGrid(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Excel Grid - DSA")
        self.resize(1920, 1200)
        self.initUI()

    def initUI(self):
        layout = QVBoxLayout()

        # Label to show the current selected cell
        self.address_label = QLabel("Selected cell: None")
        layout.addWidget(self.address_label)

        self.table = QTableWidget(10, 10)
        self.table.setHorizontalHeaderLabels([chr(65 + i) for i in range(10)])
        self.table.setVerticalHeaderLabels([str(i + 1) for i in range(10)])
        layout.addWidget(self.table)

        btn_layout = QHBoxLayout()

        clear_btn = QPushButton("Clear All")
        save_btn = QPushButton("Save")

        clear_btn.clicked.connect(self.clear_all)
        save_btn.clicked.connect(self.save_to_file)

        btn_layout.addWidget(clear_btn)
        btn_layout.addWidget(save_btn)
        layout.addLayout(btn_layout)

        self.table.currentCellChanged.connect(self.update_address)

        self.setLayout(layout)

    def update_address(self, row, col, *_):
        if row >= 0 and col >= 0:
            col_letter = chr(65 + col)
            self.address_label.setText(f"Selected cell: {col_letter}{row + 1}")

    def clear_all(self):
        self.table.clearContents()

    def save_to_file(self):
        path, _ = QFileDialog.getSaveFileName(self, "Save File", "", "CSV Files (*.csv)")
        if not path:
            return

        with open(path, "w") as file:
            for r in range(self.table.rowCount()):
                row_data = []
                for c in range(self.table.columnCount()):
                    item = self.table.item(r, c)
                    row_data.append(item.text() if item else "")
                file.write(",".join(row_data) + "\n")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ExcelGrid()
    window.show()
    sys.exit(app.exec_())
