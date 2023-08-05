const form = document.getElementById("form");
const dataTable = document.getElementById("data");

form.addEventListener("submit", (event) => {
  event.preventDefault();
  const key = document.getElementById("key").value;
  const value = document.getElementById("value").value;
  // Send the key-value pair to the Redis database
  // ...
});