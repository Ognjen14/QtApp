#include "squareobject.h"

SquareObject::SquareObject(QObject *parent)
    : QObject{parent}
{

}

QString SquareObject::borderColor() const
{
    return m_borderColor;
}

void SquareObject::setBorderColor(const QString &newBorderColor)
{
    if (m_borderColor == newBorderColor)
        return;
    m_borderColor = newBorderColor;
    emit borderColorChanged();
}

double SquareObject::coolerCurrent() const
{
    return m_coolerCurrent;
}

void SquareObject::setCoolerCurrent(double newCoolerCurrent)
{
    if (qFuzzyCompare(m_coolerCurrent, newCoolerCurrent))
        return;
    m_coolerCurrent = newCoolerCurrent;
    emit coolerCurrentChanged();
}

double SquareObject::coolerVoltage() const
{
    return m_coolerVoltage;
}

void SquareObject::setCoolerVoltage(double newCoolerVoltage)
{
    if (qFuzzyCompare(m_coolerVoltage, newCoolerVoltage))
        return;
    m_coolerVoltage = newCoolerVoltage;
    emit coolerVoltageChanged();
}

double SquareObject::detectorVoltage() const
{
    return m_detectorVoltage;
}

void SquareObject::setDetectorVoltage(double newDetectorVoltage)
{
    if (qFuzzyCompare(m_detectorVoltage, newDetectorVoltage))
        return;
    m_detectorVoltage = newDetectorVoltage;
    emit detectorVoltageChanged();
}

double SquareObject::detectorCurrent() const
{
    return m_detectorCurrent;
}

void SquareObject::setDetectorCurrent(double newDetectorCurrent)
{
    if (qFuzzyCompare(m_detectorCurrent, newDetectorCurrent))
        return;
    m_detectorCurrent = newDetectorCurrent;
    emit detectorCurrentChanged();
}

int SquareObject::idNumber() const
{
    return m_idNumber;
}

void SquareObject::setIdNumber(int newIdNumber)
{
    if (m_idNumber == newIdNumber)
        return;
    m_idNumber = newIdNumber;
    emit idNumberChanged();
}
