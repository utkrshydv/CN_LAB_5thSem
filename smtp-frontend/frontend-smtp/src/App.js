import React, { useState } from "react";
import axios from "axios";

function App() {
  const [to, setTo] = useState("");
  const [subject, setSubject] = useState("");
  const [message, setMessage] = useState("");
  const [status, setStatus] = useState("");

  const sendEmail = async () => {
    try {
      const response = await axios.post("http://localhost:5000/send-email", {
        to,
        subject,
        message,
      });
      setStatus("✅ Email sent successfully!");
    } catch (error) {
      setStatus("❌ Error: " + error.message);
    }
  };

  return (
    <div style={{ padding: "20px" }}>
      <h2>📧 Send Email</h2>
      <input
        type="email"
        placeholder="Recipient"
        value={to}
        onChange={(e) => setTo(e.target.value)}
      />
      <br /><br />
      <input
        type="text"
        placeholder="Subject"
        value={subject}
        onChange={(e) => setSubject(e.target.value)}
      />
      <br /><br />
      <textarea
        placeholder="Message"
        value={message}
        onChange={(e) => setMessage(e.target.value)}
      />
      <br /><br />
      <button onClick={sendEmail}>Send</button>
      <p>{status}</p>
    </div>
  );
}

export default App;
