public class LoginScreen {
	private boolean loggedIn = false;
	
	public boolean getLogin() {
		return this.loggedIn;
	}
	public void setLogin(boolean value) {
		this.loggedIn = value;
	}
	
	public void login(String trueLogin, String truePassword, String login, String password) {	
		if(password.equals(truePassword) && login.equals(trueLogin)) {
			setLogin(true);
		} else {
			System.out.println("\n\nLogin ou senha incorretos. Tente novamente.\n\n");
		}
	}
}
