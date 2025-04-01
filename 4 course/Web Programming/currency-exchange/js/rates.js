import { getExchangeRates } from "./api.js";
import { startTimer } from "./timer.js";

document.addEventListener("DOMContentLoaded", async () => {
    await updateExchangeRates();

    setTimeout(() => {
        location.reload();
    }, 12 * 60 * 60 * 1000); // 12 годин у мілісекундах

    startTimer();
});

async function updateExchangeRates() {
    const data = await getExchangeRates();
    if (!data || !data.rates || !data.rates["UAH"]) {
        console.error("Помилка отримання даних про курси валют.");
        return;
    }

    const baseToUAH = data.rates["UAH"];
    const tableBody = document.getElementById("ratesTableBody");

    const currencies = ["USD", "EUR", "PLN", "GBP", "JPY"];

    tableBody.innerHTML = "";

    currencies.forEach(currency => {
        if (data.rates[currency]) {
            const rateToUAH = (baseToUAH / data.rates[currency]).toFixed(2);
            const row = `<tr>
                            <td>${currency}</td>
                            <td>${rateToUAH} UAH</td>
                        </tr>`;
            tableBody.innerHTML += row;
        }
    });
}
