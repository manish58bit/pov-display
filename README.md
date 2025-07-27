# POV Display

This project demonstrates a **Persistence of Vision (POV)** display that shows the text `"JAI HIND"` using 10 LEDs mounted on a rotating arm, controlled by an **Arduino Nano** and triggered by a **Hall effect sensor**.

---

## 📸 Circuit Diagram

![Circuit Diagram](images/circuit_diagram.png)

---

### Demo Video

[![Circuit Diagram](video/pov_demo.mp4)](https://github.com/user-attachments/assets/656f1807-a8fc-4f53-99d4-23c0d0261572)



---

## 🧠 How it Works

- A Hall effect sensor detects the magnet on each rotation.
- Arduino triggers the LED pattern based on timing.
- The pattern is displayed column by column creating the illusion of full characters using POV.

---

## 🔧 Components Used

| Component            | Quantity | Description                                |
|----------------------|----------|---------------------------------------------|
| Arduino Nano         | 1        | Controls the LED pattern                   |
| LEDs                 | 10       | For POV pattern (D3–D12)                    |
| Hall Effect Sensor   | 1        | Detects rotation start (connected to D2)    |
| Resistors            | 2        | For LED current limiting                    |
| Magnet               | 1        | Mounted on stand                            |
| Battery (5v)         | 1        | Power supply                                |

---



