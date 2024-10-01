import sys
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLabel, QComboBox, QGraphicsScene, QGraphicsView, QGraphicsEllipseItem, QGraphicsSimpleTextItem
from PyQt6.QtGui import QBrush, QColor
from PyQt6.QtCore import Qt


class Node:
    def __init__(self, name):
        self.name = name
        self.friends = set()


class Graph:
    def __init__(self, nodes=None):
        self.nodes = nodes or set()

    def add_node(self, node):
        self.nodes.add(node)


class GraphUI(QWidget):
    def __init__(self, graph):
        super().__init__()

        self.graph = graph
        self.selected_profile = None
        self.compare_profile = None

        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout(self)

        self.scene = QGraphicsScene()
        self.view = QGraphicsView(self.scene)
        layout.addWidget(self.view)

        self.profile_dropdown = QComboBox()
        self.profile_dropdown.currentIndexChanged.connect(self.display_friends)
        layout.addWidget(self.profile_dropdown)

        self.compare_dropdown = QComboBox()
        self.compare_dropdown.currentIndexChanged.connect(self.compare_profiles)
        layout.addWidget(self.compare_dropdown)

        self.populate_dropdowns()

        self.setLayout(layout)
        self.setGeometry(100, 100, 800, 600)
        self.setWindowTitle('Social Network Graph')
        self.show()

    def populate_dropdowns(self):
        for node in self.graph.nodes:
            self.profile_dropdown.addItem(node.name)
            self.compare_dropdown.addItem(node.name)

    def display_friends(self, index):
        self.clear_scene()

        profile_name = self.profile_dropdown.currentText()
        self.selected_profile = next(node for node in self.graph.nodes if node.name == profile_name)

    # Pass an empty set when calling draw_graph
        self.draw_graph(set(), highlight_selected=False)


    def compare_profiles(self, index):
        if self.selected_profile is None:
            return

        self.clear_scene()

        compare_name = self.compare_dropdown.currentText()
        self.compare_profile = next(node for node in self.graph.nodes if node.name == compare_name)

        mutual_friends = self.selected_profile.friends.intersection(self.compare_profile.friends)

        self.draw_graph(mutual_friends, highlight_selected=True)

    def draw_graph(self, mutual_friends=None, highlight_selected=False):
        central_node = self.selected_profile if mutual_friends is None else None

        for i, node in enumerate(self.graph.nodes):
            item = QGraphicsEllipseItem(0, 0, 50, 50)
            item.setPos(i * 100, 100)
            brush = QBrush(Qt.GlobalColor.green if node in mutual_friends else Qt.GlobalColor.gray)
            item.setBrush(brush)
            self.scene.addItem(item)

            text_item = QGraphicsSimpleTextItem(node.name)
            text_item.setPos(i * 100 + 10, 110)
            self.scene.addItem(text_item)

            if highlight_selected and node == self.selected_profile:
                item.setBrush(QBrush(Qt.GlobalColor.red))

            if central_node is not None and node != central_node:
                central_item = QGraphicsEllipseItem(0, 0, 50, 50)
                central_item.setPos(i * 100, 300)
                central_item.setBrush(QBrush(Qt.GlobalColor.blue))
                self.scene.addItem(central_item)

        self.view.setScene(self.scene)


    def clear_scene(self):
        self.scene.clear()


def main():
    app = QApplication(sys.argv)

    node1 = Node("Alice")
    node2 = Node("Bob")
    node3 = Node("Charlie")
    node4 = Node("David")
    node5 = Node("Eve")

    node1.friends = {node2, node3}
    node2.friends = {node1, node3, node4}
    node3.friends = {node1, node2, node4}
    node4.friends = {node2, node3}
    node5.friends = set()

    graph = Graph({node1, node2, node3, node4, node5})

    gui = GraphUI(graph)

    sys.exit(app.exec())


if __name__ == '__main__':
    main()
