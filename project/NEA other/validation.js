document.getElementById("submituser").onclick  = function username_validation(){
    let username_valid = false;
    let special_characters = "-';/*";
    while (username_valid != true){
        let count = 0;
        let username = document.getElementById("username").value;
        for(let i = 0; i < username.length - 1; i++){
            for(let j= 0; j < 5; j++){
                if (username[i] == special_characters[j]){
                    count ++;
                }
            }
        }
        if (count > 0){
            document.getElementById("usernamevalid").textContent = "Username should not contain special characters: - ' ; / *";
            username_valid = false;
        }
        else{
            username_valid = true;
            document.getElementById("usernamevalid").textContent = "Username is valid.";
        }
    }

}


document.getElementById("submitpassword").onclick  = function username_validation(){
    let password_valid = false;
    while(password_valid != true){
        let password = document.getElementById("password").value;
        let confirmpassword = document.getElementById("confirmpassword").value;
        if(password.length > 11 && password.length < 36){
            if(password == confirmpassword){
                password_valid = true;
                document.getElementById("passwordvalid").textContent = "Password is valid and both passwords match.";
            }
            else{
                document.getElementById("passwordvalid").textContent = "Passwords do not match.";
            }
        }
        else{
            document.getElementById("passwordvalid").textContent = "Password should be greater than 11 characters.";

        }
    }
}
