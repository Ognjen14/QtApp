#ifndef SQUAREOBJECT_H
#define SQUAREOBJECT_H

#include <QObject>
#include <QString>

class SquareObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(double coolerCurrent READ coolerCurrent WRITE setCoolerCurrent NOTIFY coolerCurrentChanged)
    Q_PROPERTY(double coolerVoltage READ coolerVoltage WRITE setCoolerVoltage NOTIFY coolerVoltageChanged)
    Q_PROPERTY(double detectorCurrent READ detectorCurrent WRITE setDetectorCurrent NOTIFY detectorCurrentChanged)
    Q_PROPERTY(double detectorVoltage READ detectorVoltage WRITE setDetectorVoltage NOTIFY detectorVoltageChanged)
public:
    explicit SquareObject(QObject *parent = nullptr);

    QString borderColor() const;
    void setBorderColor(const QString &newBorderColor);

    double coolerCurrent() const;
    void setCoolerCurrent(double newCoolerCurrent);

    double coolerVoltage() const;
    void setCoolerVoltage(double newCoolerVoltage);

    double detectorVoltage() const;
    void setDetectorVoltage(double newDetectorVoltage);

    double detectorCurrent() const;
    void setDetectorCurrent(double newDetectorCurrent);

signals:

    void borderColorChanged();
    void coolerCurrentChanged();

    void coolerVoltageChanged();

    void detectorVoltageChanged();

    void detectorCurrentChanged();

private:
    QString m_borderColor;
    double m_coolerCurrent;
    double m_coolerVoltage;
    double m_detectorVoltage;
    double m_detectorCurrent;
};

#endif // SQUAREOBJECT_H
