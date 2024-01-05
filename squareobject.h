#pragma once

#include <QObject>
#include <QString>
/**
 * @brief The SquareObject class represents a square object with properties for ID, color, and sensor readings.
 *
 * This class defines a QObject-derived SquareObject used to represent a square-shaped object. It provides properties
 * for ID number, border color, cooler current, cooler voltage, detector current, and detector voltage. Signals are
 * emitted when these properties are modified.
 */
class SquareObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idNumber READ idNumber WRITE setIdNumber NOTIFY idNumberChanged FINAL)
    Q_PROPERTY(QString borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(double coolerCurrent READ coolerCurrent WRITE setCoolerCurrent NOTIFY coolerCurrentChanged)
    Q_PROPERTY(double coolerVoltage READ coolerVoltage WRITE setCoolerVoltage NOTIFY coolerVoltageChanged)
    Q_PROPERTY(double detectorCurrent READ detectorCurrent WRITE setDetectorCurrent NOTIFY detectorCurrentChanged)
    Q_PROPERTY(double detectorVoltage READ detectorVoltage WRITE setDetectorVoltage NOTIFY detectorVoltageChanged)
public:
    /**
     * @brief Constructor for the SquareObject class.
     * @param parent The optional parent object.
     */
    explicit SquareObject(QObject *parent = nullptr);

    /**
     * @brief Destructor for the SquareObject class.
     */
    ~SquareObject() = default;

    /**
     * @brief borderColor Retrieves the border color of the square object.
     * @return The border color as a QString.
     *
     * This function returns the current border color of the square object.
     */
    QString borderColor() const;
    /**
     * @brief setBorderColor Sets the border color of the square object.
     * @param newBorderColor The new border color to set as a QString.
     *
     * This function sets the border color of the square object to the provided color.
     * Use this method to update the border color.
     */
    void setBorderColor(const QString &newBorderColor);

    /**
     * @brief coolerCurrent Retrives the cooler current of the square object.
     * @return The cooler current as a double.
     *
     * This function returnt the current cooler current of square object.
     */
    double coolerCurrent() const;
    /**
     * @brief setCoolerCurrent Sets the cooler current of the square object.
     * @param newCoolerCurrent The new cooler current to set as double.
     *
     * This function sets cooler color of the square object to the provided current.
     * Use this method to udpate the cooler current.
     */
    void setCoolerCurrent(double newCoolerCurrent);

    /**
     * @brief Retrieves the cooler voltage of the square object.
     * @return The cooler voltage as a double value.
     *
     * This function returns the current cooler voltage of the square object.
     */
    double coolerVoltage() const;
    /**
     * @brief Sets the cooler voltage of the square object.
     * @param newCoolerVoltage The new cooler voltage to set as a double value.
     *
     * This function sets the cooler voltage of the square object to the provided voltage value.
     * Use this method to update the cooler voltage reading of the square.
     */
    void setCoolerVoltage(double newCoolerVoltage);

    /**
     * @brief Retrieves the detector voltage of the square object.
     * @return The detector voltage as a double value.
     *
     * This function returns the current detector voltage of the square object.
     */
    double detectorVoltage() const;
    /**
     * @brief Sets the detector voltage of the square object.
     * @param newDetectorVoltage The new detector voltage to set as a double value.
     *
     * This function sets the detector voltage of the square object to the provided voltage value.
     * Use this method to update the detector voltage reading of the square.
     */
    void setDetectorVoltage(double newDetectorVoltage);

    /**
     * @brief Retrieves the detector current of the square object.
     * @return The detector current as a double value.
     *
     * This function returns the current detector current of the square object.
     */
    double detectorCurrent() const;
    /**
     * @brief Sets the detector current of the square object.
     * @param newDetectorCurrent The new detector current to set as a double value.
     *
     * This function sets the detector current of the square object to the provided current value.
     * Use this method to update the detector current reading of the square.
     */
    void setDetectorCurrent(double newDetectorCurrent);

    /**
     * @brief Retrieves the ID number of the square object.
     * @return The ID number as an integer value.
     *
     * This function returns the current ID number of the square object.
     */
    int idNumber() const;
    /**
     * @brief Sets the ID number of the square object.
     * @param newIdNumber The new ID number to set as an integer value.
     *
     * This function sets the ID number of the square object to the provided ID value.
     * Use this method to update the ID number associated with the square.
     */
    void setIdNumber(int newIdNumber);

signals:

    /**
     * @brief Signal emitted when the border color of the square object changes.
     *
     * This signal is emitted whenever the border color property of the square object changes.
     */
    void borderColorChanged();

    /**
     * @brief Signal emitted when the cooler current of the square object changes.
     *
     * This signal is emitted whenever the cooler current property of the square object changes.
     */
    void coolerCurrentChanged();

    /**
     * @brief Signal emitted when the cooler voltage of the square object changes.
     *
     * This signal is emitted whenever the cooler voltage property of the square object changes.
     */
    void coolerVoltageChanged();

    /**
     * @brief Signal emitted when the detector voltage of the square object changes.
     *
     * This signal is emitted whenever the detector voltage property of the square object changes.
     */
    void detectorVoltageChanged();

    /**
     * @brief Signal emitted when the detector current of the square object changes.
     *
     * This signal is emitted whenever the detector current property of the square object changes.
     */
    void detectorCurrentChanged();

    /**
     * @brief Signal emitted when the ID number of the square object changes.
     *
     * This signal is emitted whenever the ID number property of the square object changes.
     */
    void idNumberChanged();

private:
    QString m_borderColor;      ///< The border color of the square object.
    double m_coolerCurrent;     ///< The current cooler value of the square object.
    double m_coolerVoltage;     ///< The voltage of the cooler in the square object.
    double m_detectorVoltage;   ///< The voltage of the detector in the square object.
    double m_detectorCurrent;   ///< The current detector value of the square object.
    int m_idNumber;             ///< The ID number associated with the square object.

};

