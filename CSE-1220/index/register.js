users = []
passwords = []

function signUp() {
    var wc = document.getElementById("welcome");

    var uName = document.getElementById("uName");
    var psw = document.getElementById("psw");

    users.push(uName.value);
    passwords.push(psw.value);

    wc.innerHTML = "Welcome " + uName.value + "!";
}