import { API_KEY } from "./config.js";

export async function getExchangeRates() {
    try {
        const response = await fetch(`https://api.exchangeratesapi.io/v1/latest?access_key=${API_KEY}`);
        const data = await response.json();
        return data;
    } catch (error) {
        console.error("Помилка отримання курсів валют:", error);
        return null;
    }
}