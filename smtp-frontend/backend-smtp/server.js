const express = require("express");
const nodemailer = require("nodemailer");
const bodyParser = require("body-parser");
const cors = require("cors");
require('dotenv').config();

const app = express();
app.use(cors());
app.use(bodyParser.json());

// Configure mail transporter
const transporter = nodemailer.createTransport({
  service: "gmail",
  auth: {
    user: process.env.EMAIL_USER,   // replace with your email
    pass: process.env.EMAIL_PASS       // use Gmail App Password
  }
});

// API endpoint to send email
app.post("/send-email", (req, res) => {
  const { to, subject, message } = req.body;

  const mailOptions = {
    from: "your_email@gmail.com",
    to: to,
    subject: subject,
    text: message
  };

  transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
      return res.status(500).send({ success: false, error: error.message });
    }
    res.send({ success: true, info: info.response });
  });
});

app.listen(5000, () => {
  console.log("Server running on http://localhost:5000");
});
