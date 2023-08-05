const express = require('express');
const redis = require('redis');

const app = express();
const client = redis.createClient();

app.use(express.json());

app.post('/set', (req, res) => {
  const { key, value } = req.body;

  client.set(key, value, (err, reply) => {
    if (err) {
      return res.status(500).json({
        error: err
      });
    }

    res.json({
      message: 'Data stored successfully',
      reply
    });
  });
});

app.get('/get/:key', (req, res) => {
  const { key } = req.params;

  client.get(key, (err, reply) => {
    if (err) {
      return res.status(500).json({
        error: err
      });
    }

    res.json({
      message: 'Data retrieved successfully',
      reply
    });
  });
});

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
  console.log(`Server started at http://localhost:${PORT}`);
});
