// Create angular app
var app = angular.module('validationApp', []);

// Create angular controller
app.controller('mainController', function($scope) {

	// function to submit the form after all validation has occurred			
	$scope.submitForm = function(isValid) {
		
		// check to make sure the form is completely valid
		if (isValid) { 
			alert('Email  validated');
		}

	};

});

function checkPass(){  
			
		var firpwd=document.userForm.pwd1.value;  
		var secpwd=document.userForm.pwd2.value;  


		if(firpwd != "" || secpwd != ""){
			if(firpwd==secpwd){  
				alert("Fn checkPass: Password matched!");
				return true;  
			}  
			else{  
				alert("Fn checkPass: Password must be same!");  
				return false;  
			}  
		}
		alert("Field should not be blank");
		return false;
} 

