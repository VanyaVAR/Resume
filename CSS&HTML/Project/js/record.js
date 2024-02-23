// Получаем все ссылки в шапке
var headerLinks = document.querySelectorAll('header nav ul li a');

// Обходим каждую ссылку и добавляем обработчик события
headerLinks.forEach(function(link) {
    link.addEventListener('click', function(event) {
        event.preventDefault(); // Предотвратить переход по ссылке

        var targetId = this.getAttribute('href').substring(1); // Получаем id целевого элемента

        // Получаем элемент, к которому нужно прокрутить страницу
        var targetElement = document.getElementById(targetId);

        if (targetElement) {
            // Вычисляем расстояние от верха страницы до целевого элемента
            var offsetTop = targetElement.offsetTop;

            // Плавно прокручиваем страницу к целевому элементу
            window.scrollTo({
                top: offsetTop,
                behavior: 'smooth'
            });
        }
    });
});

document.getElementById("appointmentForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Предотвратить отправку формы по умолчанию

    // Получаем значения полей формы
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    var phone = document.getElementById("phone").value;

    // Проверка номера телефона с использованием регулярного выражения
    var phonePattern = /^\+7\(\d{3}\)-\d{3}-\d{2}-\d{2}$/;

    if (!phonePattern.test(phone)) {
        // Если номер не соответствует шаблону, выводим сообщение и прерываем обработку
        alert("Пожалуйста, введите номер телефона в формате +7(XXX)-XXX-XX-XX");
        return;
    }

    // Создаем объект с данными для отправки на сервер
    var formData = {
        name: name,
        email: email,
        phone: phone
    };

    // Отправляем данные на сервер (в данном случае, выводим в консоль)
    console.log("Данные для отправки:", formData);

    // Выводим сообщение об успешной записи
    alert("Спасибо, " + name + "! Вы успешно записаны на прием.");
});
