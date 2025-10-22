//
// Created by vasimasr on 22-Oct-25.
//

#ifndef CODING4145_SKETCH_H
#define CODING4145_SKETCH_H


#include <QMainWindow>
#include <QPainter>
#include <qDebug>
#include <QMouseEvent>

class Sketch : public QMainWindow {
    Q_OBJECT
    bool sketch = false;
    float mouseX = 0;
    float mouseY = 0;
public:
    explicit Sketch(QMainWindow *parent = nullptr) : QMainWindow(parent) {
        setFixedSize(600, 600);
        setWindowTitle("coding4145");
        show();
    }
private:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        QImage image = QImage("E:\\CLionProjects\\GraphicsPrograms\\coding4145\\img.png");
        painter.drawImage(QRect(0, 0, 600, 600), image);
        painter.setPen(QColor(95, 255, 175));
        painter.setBrush(QColor(0, 0, 255));
        if (sketch) {
            painter.drawEllipse(450, 450, 90, 90);
            painter.setPen(QColor(0, 0, 255));
            painter.setBrush(QColor(0, 255, 0));
            painter.drawRect(300, 300, 150,150);
        }
    }
    void mousePressEvent(QMouseEvent *) override {
        sketch = !sketch;
        repaint();
    }
    void mouseMoveEvent(QMouseEvent* mouse) override {
        QPoint mousePoint = mouse->pos();
        mouseX = mousePoint.x();
        mouseY = mousePoint.y();
        qDebug() << mouseX << " " << mouseY;
        repaint();
    }
};


#endif //CODING4145_SKETCH_H