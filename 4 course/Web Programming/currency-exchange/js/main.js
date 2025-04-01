import { getExchangeRates } from "./api.js";
import { startTimer } from "./timer.js";

let exchangeRates = {};

document.addEventListener("DOMContentLoaded", async () => {
    await loadExchangeRates();

    setTimeout(() => {
        location.reload();
    }, 12 * 60 * 60 * 1000); // 12 годин у мілісекундах

    startTimer();
});

async function loadExchangeRates() {
    exchangeRates = await getExchangeRates();
}

function convertCurrency() {
    const amount = parseFloat(document.getElementById("amount").value);
    const fromCurrency = document.getElementById("fromCurrency").value;
    const toCurrency = document.getElementById("toCurrency").value;

    if (!exchangeRates || !exchangeRates.rates || !exchangeRates.rates[fromCurrency] || !exchangeRates.rates[toCurrency]) {
        alert("Не вдалося отримати курси валют.");
        return;
    }

    const baseRate = exchangeRates.rates["EUR"];
    const fromRate = exchangeRates.rates[fromCurrency];
    const toRate = exchangeRates.rates[toCurrency];

    const amountInBaseCurrency = (amount / fromRate) * baseRate;
    const result = (amountInBaseCurrency / baseRate) * toRate;

    const resultElement = document.getElementById("result");
    resultElement.textContent = `Результат: ${result.toFixed(2)} ${toCurrency}`;

    resultElement.classList.add("fade-in");

    const converterContainer = document.getElementById("converterContainer");
    converterContainer.classList.add("highlight");

    document.getElementById("fromCurrency").classList.add("highlight-select");
    document.getElementById("toCurrency").classList.add("highlight-select");
}

function resetFields() {
    document.getElementById("amount").value = 1;
    document.getElementById("fromCurrency").selectedIndex = 0; // USD
    document.getElementById("toCurrency").selectedIndex = 1; // EUR
    document.getElementById("result").textContent = "Результат: ";
    
    document.getElementById("result").classList.remove("fade-in");
    const converterContainer = document.getElementById("converterContainer");
    converterContainer.classList.remove("highlight");
    document.getElementById("fromCurrency").classList.remove("highlight-select");
    document.getElementById("toCurrency").classList.remove("highlight-select");
}

const showPopupBtn = document.getElementById("infoIcon");
const closePopupBtn = document.getElementById("closePopup");
const modal = document.getElementById("modal");
const overlay = document.getElementById("modalOverlay");

showPopupBtn.addEventListener("click", () => {
    modal.style.display = "block";
    overlay.style.display = "block";
});

closePopupBtn.addEventListener("click", () => {
    modal.style.display = "none";
    overlay.style.display = "none";
});

window.convertCurrency = convertCurrency;
window.resetFields = resetFields;
