public class Professor extends User {
	private String login;
	private String password;
	
	// Method to register a student grade
	// Input to send a value that will be registered in the variable grades from the Students class
	public float RegisterGrades(float grade) {
		return grade;
	}
	
	// Login related
	public void setLogin(String login) {
		this.login = login;
	}
	public String getLogin() {
		return this.login;
	}
	
	// Password related
	public void setPassword(String password) {
		this.password = password;
	}
	public String getPassword() {
		return this.password;
	}
}
